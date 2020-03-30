#include <stdio.h>
#include "printf.h"

int main()
{
  printf("--<%d>\n", ft_printf("%12s %*d", NULL, 25, 1256));
  printf("--<%d>\n", ft_printf("%-*p", 10, NULL));
  /*
  printf("--<%d>\n", ft_printf("%5%"));
  printf("--<%d>\n", ft_printf("%-5%"));
  printf("--<%d>\n", ft_printf("%05%"));
  printf("--<%d>\n", ft_printf("%-05%"));
  printf("--<%d>\n", ft_printf("%.03s", NULL));
  printf("--<%d>\n", ft_printf("%3.1s", NULL));
  printf("--<%d>\n", ft_printf("%9.1s", NULL));
  printf("--<%d>\n", ft_printf("%-3.1s", NULL));
  printf("--<%d>\n", ft_printf("%-9.1s", NULL));
  printf("--<%d>\n", ft_printf("%p", NULL));
  printf("--<%d>\n", ft_printf("%5p", NULL));
  printf("--<%d>\n", ft_printf("%2p", NULL));
  printf("--<%d>\n", ft_printf("%.p", NULL));
  printf("--<%d>\n", ft_printf("%5.p", NULL));
  printf("--<%d>\n", ft_printf("%2.p", NULL));
  printf("--<%d>\n", ft_printf("%.5p", NULL));
  printf("--<%d>\n", ft_printf("%5p", NULL));
*/
  return 0;
}
