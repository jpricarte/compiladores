# Etapa 4

Nessa etapa precisamos fazer a análise semântica do nosso
compilador.

Para entender o que deve ser feito, consulte [arquivo de definição do trabalho](./E4.pdf).

## Falta fazer:

Lista atualizada dia 25/02 às 20h45.

### [Parser](./parser.y)

1. Definir literais na tabela;
    > Possivelmente não precisamos disso.
2. Arrumar push e pop de novas tabelas (atualmente não 
podemos inserir parâmetros na tabela de função);
3. Definir parâmetros na tabela local da função;
4. Finalizar mensagens de erro;
5. Refatorar o código

### [Tabela](./table.hh)

1. Debuggar tabela para ver se as informações estão salvas 
corretamente.
    > Provavelmente a melhor forma de fazer isso é printando
    as tabelas antes de deletar, assim conseguimos ver os
    valores finais salvos em cada.

### [Testes](./testes)

1. Definir testes simples para casos aprovados
2. Definir testes simples para cada tipo de erro
    1. Identif. declarados
    2. Identif. não declarados
    3. Identif. usados incorretamente
    4. Conversão de char
    5. Conversão para char
