using System;

namespace PedraPapelTesoura
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Pedra, Papel ou Tesoura!");

            Console.Write("Escolha [pedra], [papel] ou [tesoura]: ");
            string escolhaUsuario = Console.ReadLine().ToLower();

            if (escolhaUsuario != "pedra" && escolhaUsuario != "papel" && escolhaUsuario != "tesoura")
            {
                Console.WriteLine("Erro.");
                return;
            }

           
            Random rand = new Random();
            string[] opcoes = { "pedra", "papel", "tesoura" };
            string escolhaComputador = opcoes[rand.Next(0, 3)];

            Console.WriteLine($"O computador escolheu: {escolhaComputador}");

            
            if (escolhaUsuario == escolhaComputador)
            {
                Console.WriteLine("Empate!");
            }
            else if (
                (escolhaUsuario == "pedra" && escolhaComputador == "tesoura") ||
                (escolhaUsuario == "papel" && escolhaComputador == "pedra") ||
                (escolhaUsuario == "tesoura" && escolhaComputador == "papel"))
            {
                Console.WriteLine("Você ganhou!");
            }
            else
            {
                Console.WriteLine("Você perdeu!");
            }
        }
    }
}
