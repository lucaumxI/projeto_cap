# O Enigma da Esfinge

### **Integrantes:**
####  - Lucas Nunes Garcia
####  - Rafael Banin Ferraz de Camargo
####  - João Pedro Reis Abdrade


# 🏺 O Enigma da Esfinge (The Riddle of the Sphinx)

> **⚠️ LEGACY PROJECT (2022)**
>
> This project is archived as a **museum piece** from my **first semester** of Computer Engineering.
> It represents my first steps into game development and C programming using graphical libraries.
> *The code structure, logic, and conventions reflect my knowledge level at that time and do not represent my current engineering standards.*

## 📜 Sobre o Jogo (About)

**O Enigma da Esfinge** é um jogo educativo de matemática desenvolvido em **C** utilizando a biblioteca **Raylib**. O jogador assume o papel de um explorador que deve responder corretamente a desafios aritméticos para sobreviver.

### A História (Lore)
O jogo segue a jornada de **Jose Mateus**, um explorador do interior da Bahia. Durante uma viagem ao Egito, ele encontra uma bússola misteriosa que o guia até a Grande Esfinge de Gizé. Ao despertar a criatura antiga, ele recebe um ultimato: resolver 10 enigmas matemáticos ou ser devorado.

## 🎮 Como Jogar (Gameplay)

O jogo consiste em uma bateria de perguntas matemáticas geradas aleatoriamente (Soma, Subtração, Multiplicação e Divisão).

* **Objetivo:** Acertar 10 perguntas consecutivas.
* **Pontuação:** Quanto mais rápido você responder, mais pontos ganha.
* **Vidas:** Você tem chances limitadas. Errar resulta em perda de vida.
* **Ranking:** O jogo possui um sistema de *High Score* local (salvo em arquivo txt).

### Controles
* **Teclado Numérico:** Digitar a resposta.
* **Enter:** Confirmar resposta.
* **Backspace:** Corrigir número.

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C
* **Biblioteca Gráfica:** [Raylib](https://www.raylib.com/)
* **Áudio/Assets:** Carregamento de texturas e música MP3.

## 💾 Compilação e Execução

Este projeto foi originalmente compilado para Windows. Para rodar, é necessário ter o ambiente de desenvolvimento configurado com a Raylib (MinGW/GCC).

```bash
gcc main.c -o esfinge.exe -lraylib -lopengl32 -lgdi32 -lwinmm
