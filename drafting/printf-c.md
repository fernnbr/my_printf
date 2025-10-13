Basicamente, essa é uma recriação do printf original, que é uma função que recebe uma string de formato e argumentos variáveis, e escreve na tela interpretando os especificadores de formato como %s, %d, etc. A grande sacada é: você precisa passar por cada caractere da string, procurar pelos especificadores de formato (que começam com %), extrair os argumentos corretos e processar cada um deles.

### Primeira Função - ft_printf:

A função começa preparando o terreno. 

Inicializamos um va_list chamado ap, que é basicamente um "cursor" que aponta para os argumentos variáveis que foram passados. 

O va_start(ap, s) prepara esse cursor para começar a ler os argumentos depois do primeiro parâmetro s.

é também criado um contador count que vai rastrear quantos caracteres foram efetivamente escritos. 
Isso é importante porque printf retorna o número de caracteres impressos.

Depois entramos em um loop que vai passar caractere por caractere pela string de formato:
- Se o caractere não for %, você simplesmente escreve ele na tela com write(1, &s[i], 1)
(escrever no file descriptor 1, que é stdout, um caractere de cada vez).
Incrementamos o count com o retorno do write, que diz quantos bytes foram escritos.

- Se o caractere for %, sabemos que o próximo caractere é especial – é um especificador de formato.
Pulamos para o próximo caractere (i++) e verificamos se é um dos tipos válidos usando ft_strchr("%cspdiuxX", s[i]).

Se for válido, chamamos a função ft_function_type que sabe lidar com cada tipo específico. 

Essa função recebe a string de formato e o va_list, extrai o argumento correto e processa ele.

No final do loop, fazemos outro i++ para pular depois do especificador e continuar.

Quando você sai do loop (chegou no \0 da string), chamamos va_end(ap) para "fechar" o va_list de forma limpa, e retorna quantos caracteres foram escritos.

### Segunda Função - ft_function_type:

Essa é mais direta. 

Recebemos o especificador de formato e o va_list. 

Para cada tipo possível (%, c, s, x, etc.), extraimos o argumento correto do va_list usando va_arg(ap, tipo) com o tipo apropriado, 
passa para uma função especializada que sabe converter aquele tipo para string e escrever na tela, e accumula o contador.

A razão de ter funções separadas como ft_print_s, ft_print_hex_lower, etc. é de responsabilidade única: 
cada função sabe como formatar e escrever um tipo específico. 

O Fluxo Completo:

Pensemos assim: você é um intérprete lendo uma receita (printf). 
Quando encontra uma instrução normal (caractere comum), você executa ela. 

Quando encontra uma diretiva especial (começa com %), você consulta um manual (ft_function_type) 
para saber exatamente como lidar com aquele tipo de dado, e então executa a instrução apropriada.

Isso é uma forma elegante de resolver o problema de argumentos variáveis sem saber de antemão quantos argumentos virão ou que tipos serão
