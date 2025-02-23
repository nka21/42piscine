#include "main.h"

#define UINT_MAX 4294967295

void print_error(void)
{
    write(1, "Error\n", 6);
}

int is_numeric(char c)
{
    return ('0' <= c && c <= '9');
}

/**
 * コマンドライン引数で受け取った文字列を数値に変換して
 * 別で用意された変数に格納する
 * 引数: コマンドライン引数, 格納先の変数
 * 戻り値: 0 (異常な入力) 1 (正常な入力)
 */
int input_to_uint(const char *str, unsigned int *num)
{
    unsigned long long result = 0;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;

    if (str[i] == '\0' || !is_numeric(str[i]))
        return (0);

    while (is_numeric(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        if (result > UINT_MAX)
            return (0);
        i++;
    }

    while (str[i] == ' ' || str[i] == '\t')
        i++;

    if (str[i] != '\0')
        return (0);

    *num = (unsigned int)result;
    return (1);
}

int main(int argc, char *argv[])
{
    unsigned int num = 0;
    char *file_path = "./numbers.dict";

    if (argc == 2 || argc == 3)
    {
        if (argc == 3)
            file_path = argv[1];
        if (!input_to_uint(argv[argc - 1], &num))
        {
            print_error();
            return (1);
        }
    }
    else
    {
        print_error();
        return (1);
    }
	ft_read(num);
    return (0);
}
