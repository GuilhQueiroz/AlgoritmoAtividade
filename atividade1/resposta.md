# Questão 1 - Escolha da Estrutura de Dados
Para o problema de gerenciamento de pedidos da cafeteria, a estrutura de dados mais adequada é uma **Fila de Prioridade**, em conjunto com uma **fila comum**.

## Justificativa

### 1. Processamento em ordem de chegada
Os pedidos normais devem ser processador na ordem em que chegam. Isso pode ser facilmente gerenciado por uma fila comum, onde o primeiro a entrar é o primeiro a ser servido. Portanto, uma fila é a estrutura natural para pedidos regulares.

### 2. Clientes VIP com prioridade
Clientes VIP precisam ter seus pedidos processados com prioridade máxima. Para isso, uma fila de prioridade permite organizar os elementos de forma que os pedidos mais urgentes (VIPs) sejam sempre atendidos antes dos outros, independentemente do momento em que chegaram.

### 3. Remoção de pedidos cancelados
A remoção de pedidos específicos de uma fila pode ser implementada através de uma fila auxiliar, ou através de métodos adequados para manter a integridade da fila principal. Para este caso, podemos localizar e remover o pedido.

### 4. Visualização dos pedidos
A fila também deve permitir a visualização dos pedidos em espera sem removê-los

## Conclusão
Estrutura escolhida: Fila de Prioridade com Fila Auxiliar
A combinação de uma **Fila de Prioridade** para pedidos VIP e uma **fila comum** para pedidos normais atende aos requisitos do sistema de gerenciamento de pedidos da cafeteria, permitindo o processamento eficiente e organizado.