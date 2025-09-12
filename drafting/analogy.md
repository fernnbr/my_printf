
# Printf.c

## `Makefile` (o maestro oficial)
Ele levanta a batuta e organiza a entrada de cada instrumento:

Compila cada músico (`.c`  `.o`) e junta todos em uma orquestra sinfônica compacta (`libftprintf.a`).
Também sabe mandar descansar (`clean`), zerar tudo (`fclean`) e recomeçar o ensaio (`re`).
#### > Sem ele, seria cada músico por si, sem harmonia.

## ft_printf.c (o maestro-assistente principal)

É o arquivo que inicia a música: recebe a partitura (`const char *s` com o texto e as marcações `%`), abre a “caixa de instrumentos” (`va_list`), 
percorre caractere por caractere e decide quem toca quando aparece um `%`.

#### > Ele não toca todas as notas sozinho, mas distribui para os outros músicos

## `ft_aux_printf.c` (os instrumentos de apoio)

São as “cordas de fundo” ou os músicos de base: aqui ficam as funções auxiliares para lidar com **strings, caracteres e números simples**.
#### > Entram em cena quando o maestro pede: “preciso imprimir uma string!” ou “um número!

## `ft_print_hex.c` (os metais brilhantes)
Responsável por dar o brilho da orquestra: imprime os números em formato hexadecimal (`%x` / `%X`).
#### > Quando a melodia pede algo especial, esse naipe entra com sua cor característica.

## `ft_libft.c` (o percussionista, apoio rítmico)
Aqui você reutiliza funções que já vêm da sua própria biblioteca `libft` (como manipulação de strings ou memória).
#### > São as batidas constantes que sustentam a música, sem aparecer tanto, mas fundamentais para dar firmeza.

## `ft_printf.h` (a partitura que todos leem)
É a partitura distribuída para cada músico. Define quais funções existem, seus protótipos, e inclui as bibliotecas necessárias.
#### > Assim, todos sabem quando e como devem entrar na música.

## Resumo 

- O ft_printf.c conduz a execução
- Os outros (aux, hex, libft) são instrumentos especializados.
- O header (.h) garante que todos tocam a mesma música. 
- O Makefile organiza e ensaia a orquestra até ela soar como uma sinfonia: o seu printf

# O porquê da presença de `ft_strlcpy`, `ft_strlen` e `ft_strchr`

O `printf` não imprime só números: ele também **manipula strings (sequências de caracteres)**.
Para isso, precisa de funções que já façam **operações básicas de forma segura e prática**:

#### `ft_strlen` (mede o tamanho da corda)

> Diz quantos caracteres existem antes do \0 (fim da string)
**Útil para saber quantos bytes escrever com write()**

|| Exemplo no `printf`: quando você imprime `%s`, ele precisa medir o tamanho da string para enviar de uma vez.

#### `ft_strchr` (procura uma nota dentro da partitura)

> Encontra a primeira ocorrência de um caractere dentro da string.

**Serve no printf para verificar se o símbolo depois do `%` é um dos formatadores válidos (`c`, `s`, `d`, `x`, etc.)**

|| Exemplo: if (ft_strchr("cspdiuxX%", s[i])) ...

## `ft_strlcpy` (copia com segurança 🥁)

> Copia de uma string para outra com limite de tamanho (evita overflow).

**Pode ser usada dentro do printf para criar buffers temporários, por exemplo, quando formata uma string antes de imprimir.**

#### Por que elas estão aqui então?
Essas funções da `libft` são como músicos já experientes que ele chama para tarefas específicas: 'medir, copiar e localizar'

Ou seja: elas aparecem no `ft_printf.h` porque o seu printf depende delas.
O header funciona como um caderno de contatos: lista não só as funções do `printf`, mas também as auxiliares da sua `libft` que são chamadas dentro dele.

# O papel do `printf.c`

O `printf.c` é o coração da sua orquestra: ele é o maestro executivo, ou seja, aquele que realmente rege a execução, distribui a melodia e chama os instrumentos certos.

### E o que está acontecendo? 

#### Primeiro definimos a função 

```
int ft_printf(const char *s, ...)
```

> O primeiro parâmetro `(s)` é a partitura: o texto com `%` espalhados.
> Os `...` são as funções variádicas: significam “aqui pode vir qualquer coisa” (inteiros, strings, ponteiros, etc.), conforme os `%` pedirem.

#### Agora vamos incializar (a orquestra) 

```
va_list ap;
va_start(ap, s);
```

> `va_list ap;` Cria uma caixinha para guardar os argumentos extras
> `va_start(ap, s);` Abre essa caixinha e aponta para o primeiro argumento variádico (logo após s).

***Aqui o ft_printf “liga o projetor” para conseguir acessar os parâmetros passados depois da string.*** 

### Agora vamos percorrer ("a partitura") 

```
while (s[i] != '\0')
{
    if (s[i] != '%')
        count += write(1, &s[i], 1);
    else
        // delega para funções auxiliares
}
```

> O loop `while` caminha caractere por caractere
> Se o caractere não é `%`, imprime direto.
> Se é `%`, ele precisa olhar o próximo caractere e decidir qual função auxiliar chamar.

### E com isso vamos chamar as funções (os "instrumentos certos" a serem utilizados 

Dependendo do formato (`c`, `s`, `d`, `x`, etc.), ele usa `va_arg`(ap, tipo) para extrair o próximo argumento da lista e passa para a função que sabe lidar com aquele tipo.

```
else if (s[i] == 'd' || s[i] == 'i')
    count += ft_putnbr_fd(va_arg(ap, int), 1);
else if (s[i] == 's')
    count += ft_putstr_fd(va_arg(ap, char *), 1);
else if (s[i] == 'x')
    count += ft_print_hex(va_arg(ap, unsigned int), 'x');
```

### E partimos para a finalização 

```
va_end(ap);
return (count);
```

> `va_end(ap)` fecha a caixinha de argumentos
> Retorna count, que é o número total de caracteres impressos (como o printf original faz)

> `printf.c` é o cérebro que lê a string, entende o que deve acontecer, pega os **argumentos variádicos** na ordem certa e chama **cada função especialista**




