# GCM-Bank
Repositório destinado a projeto final da matéria de Gerenciamento de Configuração e Mudanças.

O modelo de controle de versão que está sendo utilizado durante o desenvolvimento é o GitFlow. A linguagem de programação escolhida foi o C++, e as funcionalidades principais são criar conta, crédito e débito de um valor, transferência entre contas e consulta de saldo. Criamos também as novas funcionalidades de tipos de conta distintos.

Seguindo para a segunda parte do projeto, decidimos refatorar o código para JavaScript, considerando todas as funcionalidades e especificidades do projeto feito anteriormente. Fizemos uma API REST usando NodeJs com o framework Express pra construção da API, e a arquitetura foi baseada no padrão MVC. Os tipos possíveis de contas foram criados como modelos, enquanto o banco foi criado como um controlador, que tem as funções de gerenciamento das contas. No arquivo GCMBankView.js, temos interface que o usuário pode utilizar diretamente no terminal.
Os testes unitários foram criados no arquivo Tests.test.js e utiliza a dependência JEST. Já para o build, utilizamos o ncc e para os testes de qualidade o ESLint, com todas as customizações no arquivo .eslintrc.json e no .eslintignore.
As rotinas de integração foram feitas no Github Actions, com diferentes especificações para cada caso (merge na develop, tags rc ou tags rel). O arquivo .zip criado na rotina de integração das tags rc ou rel ficam como atributo na área do Actions, dentro do Github.
O Docker foi desenvolvido no arquivo Dockerfile e gera um container em caso de uma nova tag rel seja adicionada ao projeto. Além disso, ela publica o container na conta do Docker Hub.
Por último, temos os Hooks locais que forçam os commits a seguirem o formato "NUM_ISSUE - MENSAGEM" e esse NUM_ISSUE deve ser um número de uma issue já existente no projeto.
