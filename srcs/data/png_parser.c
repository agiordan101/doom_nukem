#include <unistd.h>
#include <fcntl.h>
#include <math.h>	
#include "doom_nukem.h"


// static int		read_up(char *str, int fd)
// {
// 	char	buf[1];
// 	char	tmp[ft_strlen(str) + 1];
// 	int		i;
// 	int		len;

// 	len = ft_strlen(str);
// 	tmp[len] = '\0';
// 	i = 0;
// 	while (read(fd, buf, 1) > 0 && i < (int)len)
// 	{
// 		if (buf[0] == str[i])
// 			tmp[i++] = buf[0];
// 		else
// 			i = 0;
// 	}
// 	return (i == len);
// }

static int				hexa_to_int(unsigned char *str, int size)
{
	int		nb;
	int		i;
	int		npow;
	int		bits[size * 2];

	nb = 0;
	i = 0;
	while (i < size)
	{
		bits[i * 2] = str[i] / 16;
		bits[i * 2 + 1] = str[i] % 16;
		i++;	
	}
	i = 0;
	npow = size * 2 - 1;
	while (i < size * 2)
		nb += bits[i++] * pow(16, npow--);
	return (nb);
}

static Uint32				hexa_to_uint32(unsigned char *str, int size)
{
	Uint32	nb;
	int		i;
	int		npow;
	int		bits[size * 2];

	nb = 0;
	i = 0;
	while (i < size)
	{
		bits[i * 2] = str[i] / 16;
		bits[i * 2 + 1] = str[i] % 16;
		i++;	
	}
	i = 0;
	npow = size * 2 - 1;
	while (i < size * 2)
		nb += bits[i++] * pow(16, npow--);
	return (nb);
}

static char				*get_buf(int len, int fd)
{
	char	buf[len + 1];
	char	*tmp;

	if (read(fd, buf, len) <= 0)
		return (ret_null_error("failed to read fd in get_buf"));
	buf[len] = '\0';
	tmp = buf;
	return (tmp);
}

static unsigned char	*get_ubuf(int len, int fd)
{
	unsigned char	buf[len + 1];
	unsigned char	*tmp;

	if (read(fd, buf, len) <= 0)
		return (ret_null_error("failed to read fd in get_ubuf"));
	buf[len] = '\0';
	tmp = buf;
	return (tmp);
}

static int				get_uchar_value(unsigned char *str, int size)
{
	int		value;
	int		i;

	value = 0;
	i = 0;
	while (i < size)
		value += str[i++];
	return (value);
}	

static int				check_signature(int fd)
{
	// char *line;
	unsigned char signature[8];


	if (read(fd, signature, 8) < 0) // Read de la signature
		return (ret_error("Invalid file : bad signature"));
	if (signature[0] != 137 ||
			signature[1] != 80 ||
			signature[2] != 78 ||
			signature[3] != 71 ||
			signature[4] != 13 ||
			signature[5] != 10 ||
			signature[6] != 26 ||
			signature[7] != 10)
		return (ret_error("Invalid file : bad signature"));
	// if (get_next_line(fd, &line) <= 0)
	// 	return (ret_error("bad png signature"));
	// printf("line = %s\n", line);
	return (1);
}

static int		parse_IHDR(t_png *png, int fd)
{
	char			*tmp;
	unsigned char	*utmp;

	if (!(utmp = get_ubuf(4, fd))) // LENGHT -> 13
		return (ret_error("parser_png : IHDR's lenght not found"));
	png->len = hexa_to_int(utmp, 4);
	if (png->len != 13)
		return (ret_error("parser_png : IHDR's lenght incorrect"));
	if (!(tmp = get_buf(4, fd)) || ft_strcmp(tmp, "IHDR") != 0) // TYPE -> IHDR
		return (ret_error("parser_png : IHDR not found"));
	if (!(utmp = get_ubuf(4, fd))) // width
		return (ret_error("parser_png : width not found"));
	png->width = hexa_to_int(utmp, 4);
	if (!(utmp = get_ubuf(4, fd))) // height
		return (ret_error("parser_png : height not found"));
	png->height = hexa_to_int(utmp, 4);
	if (!(utmp = get_ubuf(1, fd))) // pitch
		return (ret_error("parser_png : pitch not found"));
	png->pitch = hexa_to_int(utmp, 1);
	if (!(utmp = get_ubuf(1, fd))) // color_type
		return (ret_error("parser_png : color_type not found"));
	png->color_type = hexa_to_int(utmp, 1);
	if (!(utmp = get_ubuf(1, fd))) // compression_method
		return (ret_error("parser_png : compression_method not found"));
	png->compression_method = hexa_to_int(utmp, 1);
	if (!(utmp = get_ubuf(1, fd))) // filter_method
		return (ret_error("parser_png : filter_method not found"));
	png->filter_method = hexa_to_int(utmp, 1);
	if (!(utmp = get_ubuf(1, fd))) // interlace_method
		return (ret_error("parser_png : interlace_method not found"));
	png->interlace_method = hexa_to_int(utmp, 1);
	if (!get_ubuf(4, fd)) // saut crc
		return (ret_error("parser_png : crc not found"));
	return (1);
}

static int		parse_data(t_png *png, int fd)
{
	int			 	len;
	unsigned char	*utmp;
	int				read_len;
	int				i;

	len = png->width * png->height;
	if (!(png->data = (Uint32*)ft_memalloc(sizeof(Uint32) * len)))
		return (ret_error("parse_data : png->data allocation failed"));
	read_len = png->pitch / 2;
	i = 0;
	while (i < len)
	{
		if (!(utmp = get_ubuf(read_len, fd)))
		{
			printf("i = %d\n", i);
			return (ret_error("parse_data : invalid file"));
		}
		png->data[i++] = hexa_to_uint32(utmp, read_len);
		// printf("png->data[%d] = %u\n", i - 1,png->data[i - 1]);
	}
	return (1);
}

static int		parse_IDAT(t_png *png, int fd)
{
	char			*tmp;
	unsigned char	*utmp;

	if (!(utmp = get_ubuf(4, fd))) // len
		return (0);
	png->len = hexa_to_uint32(utmp, 4);
	printf("png->len = %u, png->width = %d, png->height = %d, png->pitch = %d, png->compressiong+m = %d, png->filter_m = %d, png->interlace_m = %d\n",
			png->len, 	   png->width, 		png->height, 	  png->pitch,	   png->compression_method,  png->filter_method, png->interlace_method);
	if (!(tmp = get_buf(4, fd))) // TYPE -> IDAT?
		return (0);
	if (ft_strcmp(tmp, "IDAT") != 0)
	{
		if (!(get_buf(png->len, fd)))
			return(ret_error("parse_IDAT : bad file"));
		if (!(utmp = get_ubuf(4, fd))) // len
			return (0);
		png->len = hexa_to_int(utmp, 4);
		if (!(tmp = get_buf(4, fd))) // TYPE -> IDAT?
			return (0);
		if (ft_strcmp(tmp, "IDAT") != 0)
			return(ret_error("parse_IDAT : IDAT not found"));
	}
	printf("name_value = %d\n", get_uchar_value((unsigned char*)tmp, 4));
	return (1);
}

int		parser_png(char *png_file)
{
	t_png			png;
	int				fd;

	if ((fd = open(png_file, O_RDONLY)) <= 0)
		return (ret_error("failed to open png_file in parser_png"));		
	if (!check_signature(fd) ||
			!parse_IHDR(&png, fd) ||
			!parse_IDAT(&png, fd) ||
			!parse_data(&png, fd))
		return (0);
	printf("size = %zu\n", sizeof(char));
	return (1);
}