# GCM-BANK
Repositório destinado a projeto final da matéria de Gerenciamento de Configuração e Mudanças.

O modelo de controle de versão que está sendo utilizado durante o desenvolvimento é o GitFlow.
De início criamos a branch main, que possui o código em produção em sua versão mais estável.
Ainda, temos a branch develop, que mantém o histórico dos commits ao longo do processo de desenvolvimento do código.
Para cada uma das funcionalidades adicionadas ao longo do tempo, criamos uma branch feature específica.
Logo após a finalização do desenvolvimento da funcionalidade, elas são integradas de volta à develop.
A linguagem de programação escolhida foi o C++ e, por isso, criamos primeiramente as features feature/accountClass, feature/bankClass e feature/mainClass.
Essas features contém o histórico de versão da criação das classes Account, Bank e o arquivo executável main com as primeiras funcionalidades do programa.
Essas funcionalidades são criar a conta, crédito e débito de um valor, transferência entre contas e consulta de saldo.
Após a finalização de cada uma das features, fizemos merge para a develop e, depois de todos os merges para a develop, um merge para a main.
Aqui finalizamos a parte 1 do projeto.
Dando continuidade, marcamos a baseline rc-1.1 para o que foi feito até então.
Criamos uma correção do bug e não permitir contas ficarem com saldo negativo. Essa mudança foi marcada com a tag rc-1.2.
Depois, corrigimos o bug para não permitir transferências, débito e crédito de valores negativos. Isso foi marcado com a tag rc-1.3.
Ambas as correções foram feitas na release/1.0 e integradas na develop logo após.
Seguindo a tarefa 2, criamos branches features feature/bonusAccount e feature/savingsAccount para as novas funcionalidades de tipos de conta distintos.
Para a última parte, começamos pondo a versão rc-1.3 em produção e a release foi marcada com a tag rel-1.3.
A versão 2 do projeto teve uma baseline estabelecida como rc-2.1 e foi criada uma release/2.0 para essa versão.
Em seguida, desenvolvemos as novas funcionalidades nas feature/savingsAccountInicialValue e feature/maximumNegativeLimit.
Elas configuram que a conta poupança seja criada com um saldo inicial informado e que as contas bônus e simples tenham limite máximo de R$ -1.000,00, respectivamente.
Depois, identificamos e corrigimos o bug para que, ao se criar uma conta simples, o saldo inicial deve ser informado. Esse bug foi corrigido pela hotfix/initialBalanceSimpleAccount, uma branch que, após finalização, foi integrada à main, release/2.0 e develop. Os conflitos foram resolvidos manualmente para cada uma, mas, para refatorar e garantir a integridade da nova versão, criamos uma nova branch feature/refactoring e depois a integramos novamente à develop com o código limpo e o bug corrigido.
Seguindo para a correção do bug de alteração da regra da bonificação para 1 ponto a cada R$150,00 recebidos, fizemos a correção na release/2.0 e estabelecemos a baseline rc-2.2 nesse ponto. Por último, mandamos a versão rc-2.2 para produção dando um merge na main e marcando com a tag rel-2.2.
