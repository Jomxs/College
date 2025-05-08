using System;
using System.Collections.Generic;

namespace FORCA
{
    class Program
    {
        static void Main(string[] args)
        {
            Jogar();
        }

        static void Jogar()
        {
            string[] dicionario = {
    "MOSTRA", "CARRETEL", "GALO", "ESCOVA", "PRESERVAR", "LAMPADA", "CADERNO",
    "JANELA", "ESPELHO", "BOLACHA", "DOZE", "ESPORTE", "FERRAMENTAS", "ENVIDO",
    "PACIENTE", "MELAO", "FELIZ", "ZUMBIDO", "DUPLO", "SEPARADO", "OLHO", "OSSO",
    "PROVERBIO", "SUOR", "INFELIZ", "TAPA", "SEMENTE", "TATUAGEM", "FINAL",
    "FLUTUADOR", "GRAVATA", "SILICONE", "TELEFONE", "PISTOLA", "TORNEIO", 
    "ZIBELINA", "ERUPCAO", "ADIVINHAR", "CERCO", "FRITAR", "TRIBO", "TRAILER",
    "RECLINAR", "CIDADE", "COMPROMISSO", "RETROVISOR", "ATLETA", "VEIA", 
    "DEMOCRACIA", "MANEQUIM" };

            Random rand = new Random();
            bool jogarNovamente = true; //usado o booleano para recomeçar o jogo no S/N

            while (jogarNovamente)
            {
                string palavra = dicionario[rand.Next(dicionario.Length)];
                char[] estado = new char[palavra.Length];
                List<char> tentativas = new List<char>();
                List<char> erros = new List<char>();

                for (int i = 0; i < estado.Length; i++) //mudado pra _ os caracteres
                    estado[i] = '_';

                int tentativasRestantes = 6;

                while (tentativasRestantes > 0 && !PalavraCompleta(estado))
                {
                    Console.Clear();
                    Console.WriteLine("====== 🔗JOGO DA FORCA🔗 ======\n");

                    Console.WriteLine("Palavra: " + string.Join(" ", estado));
                    Console.WriteLine("Letras já tentadas: " + string.Join(" ", tentativas));
                    Console.WriteLine("Tentativas restantes: " + tentativasRestantes);
                    Console.Write("\nDigite uma letra: ");

                    char chute = char.ToUpper(Console.ReadKey(true).KeyChar);
                    Console.WriteLine(chute);

                    if (!char.IsLetter(chute)) // se for difernte de uma letra
                    {
                        Console.WriteLine("Digite uma letra valida😐.");
                        Console.ReadKey();
                        continue;
                    }

                    if (tentativas.Contains(chute)) // se ja estiver 
                    {
                        Console.WriteLine("Você já ussou esta letra🤨.");
                        Console.ReadKey();
                        continue;
                    }

                    tentativas.Add(chute);  

                    if (RevelarLetra(palavra, chute, estado)) // se der bom
                    {
                        Console.WriteLine("✔");
                    }
                    else
                    {
                        tentativasRestantes--; // se der ruim
                        erros.Add(chute);
                        Console.WriteLine("✖");
                    }

                    Console.ReadKey();
                }

                Console.Clear();
                if (PalavraCompleta(estado))
                {
                    Console.WriteLine("Você ganhou IHUUUUUUUUUUUUUUL 🎉🥳! a palavra era: " + palavra);
                    Console.WriteLine($"Erros: {erros.Count}");
                }
                else
                {
                    Console.WriteLine("💀PERDEDOR, ERA MO FACIL💀! A palavra era: " + palavra);
                }

                Console.Write("\nQuer jogar mais? (😁S/N😥): ");
                char resposta = char.ToUpper(Console.ReadKey(true).KeyChar);
                jogarNovamente = (resposta == 'S');
            }
        }

        static bool PalavraCompleta(char[] estado) // se todas as letras ja forem descobertas
        {
            foreach (char c in estado)
            {
                if (c == '_') return false; 
            }
            return true;
        }

        static bool RevelarLetra(string palavra, char chute, char[] estado)
        {
            bool acertou = false;
            for (int i = 0; i < palavra.Length; i++)
            {
                if (palavra[i] == chute) // se a palavra lida no loop for igual ao chute trasforma o estado o chute
                {
                    estado[i] = chute;
                    acertou = true;
                }
            }
            return acertou;
        }
    }
}
