
Essas são as "máquinas de conversão" do seu printf. 
Cada uma pega um tipo de dado específico e sabe exatamente como transformá-lo em caracteres e colocar na tela. 

Todas seguem o mesmo padrão: fazem o trabalho, contam quantos caracteres escreveram, e retornam esse número.

#### ft_print_c - Imprimindo um Caractere

```
int	ft_print_c(int letter)
{
	return (write(1, &letter, 1));
}
```

Essa é a mais simples. 
Um caractere é um caractere – você recebe um int (porque no va_arg você extraiu como int, por causa de promoção de tipo), 
e escreve direto na tela com um único write. 

O &letter pega o endereço do int (como um ponteiro para byte), escreve 1 byte dele na tela, 
e retorna quantos bytes foram escritos (sempre 1, a menos que algo dê errado).

É praticamente sem lógica – você só está passando o dado adiante para a tela.

#### ft_print_s - Imprimindo uma String

```
int	ft_print_s(char *str)
{
	int	count;
	count = 0;
	if (str == NULL)
		return (ft_print_s("(null)"));
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		count++;
	}	
	return (count);
}
```

Aqui tem um pouco mais de lógica.

Primeiro, há uma verificação inteligente: se o ponteiro para a string for NULL, você não pode simplesmente escrever na tela (isso causaria segmentation fault). 

Então você chama a função recursivamente passando a string literal "(null)". É uma forma elegante de dizer "se receber lixo, imprima '(null)' e fim de papo."

Depois você entra em um loop simples: enquanto não chegar no terminador nulo (\0 que marca o fim de uma string em C), você escreve cada caractere individual, 
incrementa o ponteiro para o próximo caractere, e incrementa o contador.

A razão de escrever caractere por caractere é consistência com o resto do código – tudo usa write(1, ..., 1) para manter as coisas uniformes e rastreáveis.
No final, retorna quantos caracteres foram escritos.

#### ft_print_nbr - Imprimindo um Número Inteiro com Sinal

```
int	ft_print_nbr(int n)
{
	char	nb;
	int		count;
	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		count++;
	}
	if (n >= 10)
		count += ft_print_nbr(n / 10);
	nb = (n % 10) + '0';
	count += write(1, &nb, 1);
	return (count);
}
```

Essa é mais sofisticada. 
Você precisa converter um número em seus dígitos e escrever cada um.

#### O Case Especial:
Primeiro, há um caso especial para -2147483648. 
Por quê? Porque em C, o int assinado vai de -2147483648 a 2147483647. 
Se você tentar fazer n *= -1 em -2147483648, você sai do intervalo (o positivo correspondente não existe em um int). 
Então você trata esse número como uma string fixa e pronto.

Tratando o Sinal:
Se o número for negativo (mas não for o case especial), você escreve um "-" na tela, incrementa o contador, e depois transforma o número para positivo multiplicando por -1.

Recursão para Extrair Dígitos:
Aqui vem a sacada: você quer imprimir os dígitos da esquerda para a direita. 
Se você tem 123, precisa imprimir 1, depois 2, depois 3. A forma elegante de fazer isso sem inverter é com recursão:

Se o número tem 10 ou mais (ou seja, tem múltiplos dígitos), você chama a função recursivamente com n / 10. Então 123 vira 12, que vira 1, que vira 0, e só então começa a voltar.
A cada retorno da recursão, você imprime o dígito atual usando (n % 10) + '0'. O % 10 pega o último dígito (123 % 10 = 3), e + '0' transforma o número em seu caractere ASCII correspondente (3 vira '3').

É uma forma muito elegante de "reverter" a ordem dos dígitos sem precisar de um array ou string temporária.

#### ft_print_unbr - Imprimindo um Número Sem Sinal
int	ft_print_unbr(unsigned int n)

```
{
	char	nb;
	int		count;
	count = 0;
	if (n >= 10)
		count += ft_print_unbr(n / 10);
	nb = (n % 10) + '0';
	count += write(1, &nb, 1);
	return (count);
}
```

Essa é basicamente a mesma lógica que ft_print_nbr, mas muito mais simples porque:

Não há sinal para tratar – é sempre positivo.
Não há case especial de overflow – unsigned int não tem aquele problema.

Então você só usa a recursão pura: divida por 10 recursivamente até chegar a um dígito único, depois na volta imprima cada dígito.

O Padrão Que Liga Tudo
Veja só: cada função, por mais diferente que seja, segue o mesmo contrato:

Recebe um tipo específico
Escreve na tela usando write(1, ..., 1)
Conta quantos bytes foram escritos
Retorna o count

Isso permite que na função ft_function_type você faça count += ft_print_X(...) com confiança – sabe que cada uma vai retornar um número que você pode somar.
É um design muito limpo: separação de responsabilidades, cada função faz uma coisa bem feita, e tudo se encaixa perfeitamente no printf maior.
