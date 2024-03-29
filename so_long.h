/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:26:26 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/21 21:46:43 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>

# include "minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_ESC 53

# define X 704
# define YW 384

typedef struct s_player {
	void	*img_mario;
	int		flag_p;
	int		x;
	int		y;
	int		f_counter;
}				t_player;

typedef struct s_col {
	int		flag_c;
	int		flag_c_counter;
	void	*img_col1;
	void	*img_col2;
	void	*img_col3;
	void	*img_col4;
	void	*img_col5;
	void	*img_col6;
}				t_col;

typedef struct s_end {
	int		flag_e;
	void	*img_end1;
	void	*img_end2;
	void	*img_end3;
	void	*img_end4;
}				t_end;

typedef struct s_map {
	char	**real_map;
	int		max_x;
	int		max_y;
	int		min_x;
	int		min_y;
	int		flag_x_min;
	int		flag_y_min;
	int		flag_x_max;
	int		flag_y_max;
	int		move_x;
	int		move_y;
	int		size_x;
	int		size_y;
	void	*img_wall;
	void	*img_fn;
}				t_map;

typedef struct s_struct {
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_size_x;
	int			win_size_y;
	void		*img_end;
	void		*img_col;
	void		*img_ene;
	int			finished;
	int			anim_counter;
	t_player	player;
	t_col		col;
	t_end		end;
	t_map		map;
}				t_struct;

void	parsing(int argc, char **argv, t_struct *mlx);
int		destroy_win(t_struct *mlx);

int		key_pressed(int button, t_struct *mlx);

void	init(int argc, char **argv, t_struct *mlx);
void	init_player(t_struct *mlx);
void	init_end(t_struct *mlx);
void	init_col(t_struct *mlx);
void	init_win(t_struct *mlx);

int		render_map(t_struct *mlx);
void	free_map(char **map);
void	fill_min_max(t_struct *mlx, int value);
void	find_pos(t_struct *mlx);

void	check_if_map_ok(t_struct *mlx, char **map, int x_cnt, int y_counter);
void	check_if_playable(t_struct *mlx, char **map, int x_cnt, int y_counter);
void	check_if_wall_ok(char **map, int x_counter, int y_counter);

void	route_error(char **map, char **temp);
void	char_error(char **map);
void	check_arg_error(int argc, char **argv);
void	error_not_rectangle(void);
void	wall_error(char **map);

int		is_map_size_ok(int fd, int *x_counter, int *y_counter);

#endif
