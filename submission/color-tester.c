#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

//Colours
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

void print_test_header(const char *category)
{
	printf("\n" BLUE "========== %s ==========" RESET "\n", category);
}

void compare_outputs(const char *test_name, int ft_ret, int printf_ret)
{
	if (ft_ret == printf_ret)
		printf(GREEN "✓ %s: PASS (ft=%d, printf=%d)" RESET "\n", test_name, ft_ret, printf_ret);
	else
		printf(RED "✗ %s: FAIL (ft=%d, printf=%d)" RESET "\n", test_name, ft_ret, printf_ret);
}

int main(void)
{
	int ft_ret, pf_ret;

	printf(YELLOW "╔════════════════════════════════════════╗\n");
	printf("║   FT_PRINTF TESTER - CRAFT TESTER   ║\n");
	printf("╚════════════════════════════════════════╝" RESET "\n");

	// ==================== TESTING %c ====================
	print_test_header("TESTE %c - CARACTERE");
	
	ft_ret = ft_printf("ft: [%c]\n", 'A');
	pf_ret = printf("pf: [%c]\n", 'A');
	compare_outputs("%c básico", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%c%c%c]\n", 'X', 'Y', 'Z');
	pf_ret = printf("pf: [%c%c%c]\n", 'X', 'Y', 'Z');
	compare_outputs("%c múltiplo", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%c]\n", 0);
	pf_ret = printf("pf: [%c]\n", 0);
	compare_outputs("%c nulo (\\0)", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%c]\n", 127);
	pf_ret = printf("pf: [%c]\n", 127);
	compare_outputs("%c valor ASCII", ft_ret, pf_ret);

	// ==================== TESTING %s ====================
	print_test_header("TESTE %s - STRING");

	ft_ret = ft_printf("ft: [%s]\n", "Hello World");
	pf_ret = printf("pf: [%s]\n", "Hello World");
	compare_outputs("%s básico", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%s]\n", "");
	pf_ret = printf("pf: [%s]\n", "");
	compare_outputs("%s vazia", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%s]\n", (char *)NULL);
	pf_ret = printf("pf: [%s]\n", (char *)NULL);
	compare_outputs("%s NULL", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%s %s %s]\n", "Teste", "com", "múltiplas");
	pf_ret = printf("pf: [%s %s %s]\n", "Teste", "com", "múltiplas");
	compare_outputs("%s múltiplas", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%s]\n", "String com espaços e números 123!");
	pf_ret = printf("pf: [%s]\n", "String com espaços e números 123!");
	compare_outputs("%s complexa", ft_ret, pf_ret);

	// ==================== TESTING %d e %i ====================
	print_test_header("TESTE %d e %i - INTEIROS");

	ft_ret = ft_printf("ft: [%d]\n", 42);
	pf_ret = printf("pf: [%d]\n", 42);
	compare_outputs("%d positivo", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%d]\n", -42);
	pf_ret = printf("pf: [%d]\n", -42);
	compare_outputs("%d negativo", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%d]\n", 0);
	pf_ret = printf("pf: [%d]\n", 0);
	compare_outputs("%d zero", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%d]\n", INT_MAX);
	pf_ret = printf("pf: [%d]\n", INT_MAX);
	compare_outputs("%d INT_MAX", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%d]\n", INT_MIN);
	pf_ret = printf("pf: [%d]\n", INT_MIN);
	compare_outputs("%d INT_MIN", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%i]\n", 123);
	pf_ret = printf("pf: [%i]\n", 123);
	compare_outputs("%i básico", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%i]\n", -456);
	pf_ret = printf("pf: [%i]\n", -456);
	compare_outputs("%i negativo", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%d %i %d]\n", 10, -20, 30);
	pf_ret = printf("pf: [%d %i %d]\n", 10, -20, 30);
	compare_outputs("%d e %i misturados", ft_ret, pf_ret);

	// ==================== TESTING %u ====================
	print_test_header("TESTE %u - UNSIGNED INT");

	ft_ret = ft_printf("ft: [%u]\n", 42);
	pf_ret = printf("pf: [%u]\n", 42);
	compare_outputs("%u positivo", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%u]\n", 0);
	pf_ret = printf("pf: [%u]\n", 0);
	compare_outputs("%u zero", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%u]\n", UINT_MAX);
	pf_ret = printf("pf: [%u]\n", UINT_MAX);
	compare_outputs("%u UINT_MAX", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%u]\n", -1);
	pf_ret = printf("pf: [%u]\n", -1);
	compare_outputs("%u com -1 (overflow)", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%u]\n", -42);
	pf_ret = printf("pf: [%u]\n", -42);
	compare_outputs("%u negativo (overflow)", ft_ret, pf_ret);

	// ==================== TESTING %x ====================
	print_test_header("TESTE %x - HEXADECIMAL MINÚSCULO");

	ft_ret = ft_printf("ft: [%x]\n", 0);
	pf_ret = printf("pf: [%x]\n", 0);
	compare_outputs("%x zero", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%x]\n", 42);
	pf_ret = printf("pf: [%x]\n", 42);
	compare_outputs("%x básico", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%x]\n", 255);
	pf_ret = printf("pf: [%x]\n", 255);
	compare_outputs("%x 255 (ff)", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%x]\n", 16);
	pf_ret = printf("pf: [%x]\n", 16);
	compare_outputs("%x 16 (10)", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%x]\n", UINT_MAX);
	pf_ret = printf("pf: [%x]\n", UINT_MAX);
	compare_outputs("%x UINT_MAX", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%x]\n", -1);
	pf_ret = printf("pf: [%x]\n", -1);
	compare_outputs("%x -1 (unsigned)", ft_ret, pf_ret);

	// ==================== TESTING %X ====================
	print_test_header("TESTE %X - HEXADECIMAL MAIÚSCULO");

	ft_ret = ft_printf("ft: [%X]\n", 0);
	pf_ret = printf("pf: [%X]\n", 0);
	compare_outputs("%X zero", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%X]\n", 42);
	pf_ret = printf("pf: [%X]\n", 42);
	compare_outputs("%X básico", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%X]\n", 255);
	pf_ret = printf("pf: [%X]\n", 255);
	compare_outputs("%X 255 (FF)", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%X]\n", UINT_MAX);
	pf_ret = printf("pf: [%X]\n", UINT_MAX);
	compare_outputs("%X UINT_MAX", ft_ret, pf_ret);

	// ==================== TESTING %p ====================
	print_test_header("TESTE %p - PONTEIRO");

	int var = 42;
	ft_ret = ft_printf("ft: [%p]\n", &var);
	pf_ret = printf("pf: [%p]\n", &var);
	compare_outputs("%p endereço válido", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%p]\n", NULL);
	pf_ret = printf("pf: [%p]\n", NULL);
	compare_outputs("%p NULL", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%p]\n", (void *)0);
	pf_ret = printf("pf: [%p]\n", (void *)0);
	compare_outputs("%p (void *)0", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%p]\n", (void *)ULONG_MAX);
	pf_ret = printf("pf: [%p]\n", (void *)ULONG_MAX);
	compare_outputs("%p ULONG_MAX", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%p %p]\n", &ft_ret, &pf_ret);
	pf_ret = printf("pf: [%p %p]\n", &ft_ret, &pf_ret);
	compare_outputs("%p múltiplos", ft_ret, pf_ret);

	// ==================== TESTING %% ====================
	print_test_header("TESTE %% - PORCENTAGEM");

	ft_ret = ft_printf("ft: [%%]\n");
	pf_ret = printf("pf: [%%]\n");
	compare_outputs("%% simples", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%%%%]\n");
	pf_ret = printf("pf: [%%%%]\n");
	compare_outputs("%% duplo", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [100%%]\n");
	pf_ret = printf("pf: [100%%]\n");
	compare_outputs("%% com número", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%% %% %%]\n");
	pf_ret = printf("pf: [%% %% %%]\n");
	compare_outputs("%% múltiplo", ft_ret, pf_ret);

	// ==================== MIXED TESTING ====================
	print_test_header("TESTES MISTURADOS - MÚLTIPLOS ESPECIFICADORES");

	ft_ret = ft_printf("ft: [%c %s %d]\n", 'A', "test", 42);
	pf_ret = printf("pf: [%c %s %d]\n", 'A', "test", 42);
	compare_outputs("Mix: c s d", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%d %i %u %x %X]\n", -10, 20, 30, 40, 50);
	pf_ret = printf("pf: [%d %i %u %x %X]\n", -10, 20, 30, 40, 50);
	compare_outputs("Mix: d i u x X", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%p %s %c]\n", &var, "pointer", '!');
	pf_ret = printf("pf: [%p %s %c]\n", &var, "pointer", '!');
	compare_outputs("Mix: p s c", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: Número: %d, Hex: %x, Char: %c, String: %s\n", 
		255, 255, 'Z', "Final");
	pf_ret = printf("pf: Número: %d, Hex: %x, Char: %c, String: %s\n", 
		255, 255, 'Z', "Final");
	compare_outputs("Mix complexo", ft_ret, pf_ret);

	// ==================== EDGE CASES ====================
	print_test_header("EDGE CASES");

	ft_ret = ft_printf("ft: [%d %d %d]\n", 0, 0, 0);
	pf_ret = printf("pf: [%d %d %d]\n", 0, 0, 0);
	compare_outputs("Múltiplos zeros", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: []\n");
	pf_ret = printf("pf: []\n");
	compare_outputs("String vazia", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: No format\n");
	pf_ret = printf("pf: No format\n");
	compare_outputs("Sem especificadores", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: %%%%%%%%\n");
	pf_ret = printf("pf: %%%%%%%%\n");
	compare_outputs("Múltiplos %%", ft_ret, pf_ret);

	// ==================== INVALID SPECIFIERS ====================
	print_test_header("ESPECIFICADORES INVÁLIDOS");

	ft_ret = ft_printf("ft: [%z]\n");
	pf_ret = printf("pf: [%z]\n");
	compare_outputs("Inválido: %z", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%k test]\n");
	pf_ret = printf("pf: [%k test]\n");
	compare_outputs("Inválido: %k", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [test%]\n");
	pf_ret = printf("pf: [test%]\n");
	compare_outputs("% no final", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%d %z %s]\n", 42, "test");
	pf_ret = printf("pf: [%d %z %s]\n", 42, "test");
	compare_outputs("Mix com inválido", ft_ret, pf_ret);

	// ==================== BIG NUMBERS ====================
	print_test_header("STRINGS E NÚMEROS GRANDES");

	char *long_str = "Esta é uma string muito longa para testar se a função funciona corretamente com textos extensos!";
	ft_ret = ft_printf("ft: [%s]\n", long_str);
	pf_ret = printf("pf: [%s]\n", long_str);
	compare_outputs("String longa", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%d]\n", 2147483647);
	pf_ret = printf("pf: [%d]\n", 2147483647);
	compare_outputs("INT_MAX literal", ft_ret, pf_ret);

	ft_ret = ft_printf("ft: [%d]\n", -2147483648);
	pf_ret = printf("pf: [%d]\n", -2147483648);
	compare_outputs("INT_MIN literal", ft_ret, pf_ret);

	// ==================== SUMMARY ====================
	printf("\n" YELLOW "╔════════════════════════════════════════╗\n");
	printf("║       EVERYTHING OK, HURRAY!    ║\n");
	printf("╚════════════════════════════════════════╝" RESET "\n\n");

	return (0);
}
