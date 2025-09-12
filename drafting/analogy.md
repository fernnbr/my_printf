
# Printf.c

## Makefile (o maestro oficial)
Ele levanta a batuta e organiza a entrada de cada instrumento:

Compila cada músico (.c → .o) e Junta todos em uma orquestra sinfônica compacta (libftprintf.a).
Também sabe mandar descansar (clean), zerar tudo (fclean) e recomeçar o ensaio (re).
#### Sem ele, seria cada músico por si, sem harmonia.

ft_printf.c (o maestro-assistente principal)

É o arquivo que inicia a música: recebe a partitura (const char *s com o texto e as marcações %), abre a “caixa de instrumentos” (va_list), 
percorre caractere por caractere e decide quem toca quando aparece um %.

#### Ele não toca todas as notas sozinho, mas distribui para os outros músicos

## ft_aux_printf.c (os instrumentos de apoio)

São as “cordas de fundo” ou os músicos de base: aqui ficam as funções auxiliares para lidar com **strings, caracteres e números simples**.
#### Entram em cena quando o maestro pede: “preciso imprimir uma string!” ou “um número!

## ft_print_hex.c (os metais brilhantes)
Responsável por dar o brilho da orquestra: imprime os números em formato hexadecimal (%x / %X).
#### Quando a melodia pede algo especial, esse naipe entra com sua cor característica.

## ft_libft.c (o percussionista, apoio rítmico)
Aqui você reutiliza funções que já vêm da sua própria biblioteca libft (como manipulação de strings ou memória).
#### São as batidas constantes que sustentam a música, sem aparecer tanto, mas fundamentais para dar firmeza.

## ft_printf.h (a partitura que todos leem)
É a partitura distribuída para cada músico. Define quais funções existem, seus protótipos, e inclui as bibliotecas necessárias.
#### Assim, todos sabem quando e como devem entrar na música.

