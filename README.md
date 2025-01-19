# Serial Communication

O projeto consiste na programação da BitDogLab para implementar uma rotina que utiliza a comunicação serial para controlar o LED RGB, o buzzer e configurar a placa no modo BOOTSEL.

---

## **GPIOs Utilizados**

| GPIO | Componente | Configuração |
|------------|------|--------|
| **21** | Buzzer | Sinal PWM |
| **13** | Vermelho do LED RGB | Saída Digital |
| **11** | Verde do LED RGB | Saída Digital |
| **12** | Azul do LED RGB | Saída Digital |

---

## **Funcões do Teclado**  

| Tecla | Função |
|-------|--------|
| `0` | Desliga LED RGB |
| `1` | Acende o **vermelho** do LED RGB |
| `2` | Acende o **verde** do LED RGB |
| `3` | Acende o **azul** do LED RGB |
| `4` | Acende a cor **branca** no LED RGB |
| `5` | Aciona o **buzzer** por 2 segundo |
| `6` | Coloca a Raspberry Pi Pico W em modo de armazenamento |

---

## **Link do Vídeo**  

https://drive.google.com/file/d/1kHB-3iVN0cjUvGW-67kiOPILAduvIpZV/view?usp=sharing