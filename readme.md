### SafeTrace - Rastreamento de Exposição à Gripe

## Descrição do Problema de Saúde

Após a pandemia de Covid-19, a conscientização sobre a prevenção de doenças respiratórias aumentou significativamente. A gripe, causada pelo vírus Influenza A, continua sendo uma ameaça, responsável por milhares de mortes anualmente. A detecção oportuna das exposições ao vírus é desafiadora devido à sua natureza contagiosa, resultando na disseminação não controlada da doença. O SafeTrace surge como uma solução para identificar exposições à gripe, promovendo medidas preventivas e conscientização.

## Visão Geral da Solução Proposta

O SafeTrace utiliza o ESP32 e o sensor ultrassônico HC-SR04 para rastrear a distância entre dispositivos, emitindo alertas quando a proximidade atinge um limite. A aplicação envia dados para um servidor MQTT (Tago.io), permitindo a monitorização remota. O objetivo é prevenir a propagação descontrolada da gripe, fornecendo alertas a usuários próximos a casos confirmados.

## Configuração e Execução da Aplicação

1. **Hardware Necessário:**
   - ESP32
   - Sensor Ultrassônico HC-SR04

2. **Configuração Inicial:**
   - Clone este repositório em seu ambiente de desenvolvimento.
   - O código está disponível na pasta "codigo fonte".
   - Instale as bibliotecas necessárias: `ArduinoJson`, `EspMQTTClient`.

3. **Configuração no Wokwi:**
   - Acesse [Wokwi](https://wokwi.com/projects/382284528343665665).
   - Importe o código e simule o projeto.

4. **Configuração do Sensor:**
   - Conecte o sensor HC-SR04 ao ESP32 (verifique os pinos no código).
   - Certifique-se de configurar corretamente as credenciais WiFi e MQTT.

5. **Execução da Aplicação:**
   - Compile e envie o código para o ESP32.
   - Monitore a saída serial para verificar a conexão WiFi e MQTT.
   - Visualize as mensagens MQTT enviadas para o servidor.

## Simulação do Projeto no Wokwi

Acesse a [simulação no Wokwi](https://wokwi.com/projects/382284528343665665) para testar o projeto em um ambiente virtual.
