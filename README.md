# Projeto: Controle de LEDs e Buzzer com RP2040 (BitDogLab)

Este projeto utiliza a placa **BitDogLab**, baseada no microcontrolador **RP2040**, para controlar três LEDs (verde, azul e vermelho) e um buzzer através de comandos recebidos via **porta serial** (USB). O controle é feito por meio de números de 1 a 7, que ativam diferentes ações no sistema embarcado.

## Componentes Necessários

- **Placa BitDogLab** (baseada no microcontrolador RP2040)
- **LEDs**:
  - 1 LED Verde (conectado no GPIO 11)
  - 1 LED Azul (conectado no GPIO 12)
  - 1 LED Vermelho (conectado no GPIO 13)
- **Buzzer**:
  - 1 Buzzer (conectado no GPIO 21)
- **Resistores** para LEDs (dependendo da configuração)
- **Cabos** de conexão

## Funcionalidade

O sistema é controlado via **porta serial** (USB) e aceita os seguintes comandos numéricos de 1 a 7:

- **1**: Ligar o LED verde (GPIO 11)
- **2**: Ligar o LED azul (GPIO 12)
- **3**: Ligar o LED vermelho (GPIO 13)
- **4**: Ligar todos os LEDs (luz branca)
- **5**: Desligar todos os LEDs
- **6**: Acionar o buzzer por 2 segundos
- **7**: Reiniciar o RP2040 no modo **Bootloader**

## Vídeo de Demonstração
[![Vídeo de Demonstração](https://i.ytimg.com/vi/kEJRiJeWUP0/hq720_2.jpg?sqp=-oaymwEoCJUDENAFSFryq4qpAxoIARUAAIhC0AEB2AEB4gEKCBgQAhgGOAFAAQ==&rs=AOn4CLC0BxD9g6Z8w7pd8a2XNGtGHcbKMQ)](https://www.youtube.com/shorts/kEJRiJeWUP0O)


## Requisitos

- **Ambiente de desenvolvimento** com o SDK da Raspberry Pi Pico (Pico SDK)
- **Compilador**: GCC para ARM
- **Ferramenta de upload**: `picotool` ou outra ferramenta de carregamento do arquivo `.uf2`

## Conexões

- **LED Verde**: GPIO 11
- **LED Azul**: GPIO 12
- **LED Vermelho**: GPIO 13
- **Buzzer**: GPIO 21

Para garantir o funcionamento adequado dos LEDs, é necessário usar um resistor em série (geralmente entre 220Ω e 1kΩ) com cada LED.

## Compilação e Carregamento

### 1. Instalar o SDK da Raspberry Pi Pico

Siga as instruções oficiais do [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk) para configurar o ambiente de desenvolvimento.

### 2. Compilar o Código

Para compilar o código, execute os seguintes passos:

1. Clone o repositório ou crie um novo diretório para o projeto.
2. Coloque o código-fonte fornecido no diretório do projeto.
3. Crie um diretório `build` e execute o CMake:

```bash
mkdir build
cd build
cmake ..
make
