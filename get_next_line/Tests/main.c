/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:28:40 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/09/14 12:30:58 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Assuming your get_next_line function signature
char *get_next_line(int fd);

void test_file(const char *filename)
{
    int fd;
    char *line;
    int line_count = 1;

    printf("=== Testing file: %s ===\n", filename);
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", line_count, line);
        if (strlen(line) > 0 && line[strlen(line) - 1] != '\n')
            printf("\n");
        free(line);
        line_count++;
    }

    printf("Total lines read: %d\n", line_count - 1);
    close(fd);
    printf("\n");
}

void test_stdin(void)
{
    char *line;
    int line_count = 1;

    printf("=== Testing stdin (reading from terminal input) ===\n");
    printf("Type your text line by line. Press Ctrl+D (Linux/Mac) or Ctrl+Z (Windows) to finish:\n");
    printf("----------------------------------------\n");

    while ((line = get_next_line(0)) != NULL)
    {
        printf("Line %d received: %s", line_count, line);
        if (strlen(line) > 0 && line[strlen(line) - 1] != '\n')
            printf("\n");
        free(line);
        line_count++;
    }

    printf("----------------------------------------\n");
    printf("Total lines read from stdin: %d\n", line_count - 1);
    printf("\n");
}

void test_multiple_files(int file_count, char **filenames)
{
    int *fds;
    char *line;
    int i;

    printf("=== Testing multiple files simultaneously ===\n");
    
    fds = malloc(sizeof(int) * file_count);
    if (!fds)
    {
        printf("Memory allocation failed\n");
        return;
    }

    // Open all files
    for (i = 0; i < file_count; i++)
    {
        fds[i] = open(filenames[i], O_RDONLY);
        if (fds[i] == -1)
        {
            printf("Error opening file: %s\n", filenames[i]);
            fds[i] = -1;
        }
    }

    // Read one line from each file in round-robin fashion
    int active_files = file_count;
    int round = 1;
    
    while (active_files > 0)
    {
        printf("--- Round %d ---\n", round);
        for (i = 0; i < file_count; i++)
        {
            if (fds[i] != -1)
            {
                line = get_next_line(fds[i]);
                if (line != NULL)
                {
                    printf("%s: %s", filenames[i], line);
                    if (strlen(line) > 0 && line[strlen(line) - 1] != '\n')
                        printf("\n");
                    free(line);
                }
                else
                {
                    printf("%s: EOF reached\n", filenames[i]);
                    close(fds[i]);
                    fds[i] = -1;
                    active_files--;
                }
            }
        }
        round++;
    }

    free(fds);
    printf("\n");
}

void print_usage(const char *program_name)
{
    printf("Usage:\n");
    printf("  %s <file1> [file2] [file3] ...    # Test with one or more files\n", program_name);
    printf("  %s --stdin                        # Test with terminal input\n", program_name);
    printf("  %s --multi <file1> <file2> ...   # Test multiple files simultaneously\n", program_name);
    printf("\nExamples:\n");
    printf("  %s test.txt                       # Read from single file\n", program_name);
    printf("  %s file1.txt file2.txt           # Read from multiple files sequentially\n", program_name);
    printf("  %s --stdin                        # Read from terminal input\n", program_name);
    printf("  %s --multi file1.txt file2.txt   # Read from multiple files in round-robin\n", program_name);
    printf("  echo \"Hello\\nWorld\" | %s --stdin # Pipe input to test\n", program_name);
}

int main(int argc, char **argv)
{
    int i;

    if (argc == 1)
    {
        print_usage(argv[0]);
        return 1;
    }

    // Test with terminal input
    if (argc == 2 && strcmp(argv[1], "--stdin") == 0)
    {
        test_stdin();
        return 0;
    }

    // Test multiple files simultaneously
    if (argc > 2 && strcmp(argv[1], "--multi") == 0)
    {
        if (argc == 2)
        {
            printf("Error: --multi requires at least one filename\n");
            print_usage(argv[0]);
            return 1;
        }
        test_multiple_files(argc - 2, &argv[2]);
        return 0;
    }

    // Test files sequentially
    for (i = 1; i < argc; i++)
    {
        test_file(argv[i]);
    }

    return 0;
}
