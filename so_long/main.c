/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:24:05 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/21 21:38:18 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char *argv[])
{
    int fd;

    if (argc != 2)
    {
        ft_printf("Error\nYou must provide exactly 1 .ber map to play the game."
            "\nUsage: %s <file_path>\n", argv[0]);
        return (1);
    }
    fd = open(argv[0], O_RDONLY);
    if (fd)
    play(argv[1]);
}