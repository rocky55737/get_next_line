#include "get_next_line.h"

static size_t my_strlen(char const *str)
{
    size_t len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    return (len);
}

static char *ft_strcat (char *dest, char *src)
{
    int dest_index;
    int src_index;

    dest_index = 0;
    src_index = 0;
    while (dest[dest_index] && src[src_index] != '\n')
    {
        dest[dest_index + src_index] = src[src_index];
        src_index++;
    }
    dest[dest_index + src_index] = 0;
    return (dest);
}

static size_t ft_strcpy(char *dest, char *src)
{
    size_t len;
    size_t counter;

    counter = 0;
    len = my_strlen(src);
    while (counter < len)
    {
        dest[counter] = src[counter];
        counter++;
    }
    dest[counter] = '\0';
    return (len);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len_s1;
    size_t len_s2;
    char *joined_str;

    len_s1 = my_strlen(s1);
    len_s2 = my_strlen(s2);
    joined_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
    if (!joined_str)
    {
        return (0);
    }
    ft_strcpy(joined_str, (char *)s1);
    ft_strcat(joined_str, (char *)s2);
    return (joined_str);
}

char *ft_substr(char const *s, unsigned int start)
{
    char *sub_string;
    size_t cnt;
    size_t s_len;

    s_len = my_strlen(s);
    sub_string = (char *)malloc(sizeof(char) * (s_len - start));
    if (!sub_string)
    {
        return (0);
    }
    cnt = 0;
    while (start + cnt < s_len)
    {
        sub_string[cnt] = sub_string[start + cnt];
        cnt++;
    }
    sub_string[cnt] = 0;
    return (sub_string);
}