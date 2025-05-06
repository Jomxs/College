using System;

namespace par_impar
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Vamos jogar Par ou Ímpar!");
            
   
            Console.Write("Escolha [par] ou [impar]: ");
            string escolhaUsuario = Console.ReadLine().ToLower(); // scanf pra minusculo

            if (escolhaUsuario != "par" && escolhaUsuario != "impar")
            {
                Console.WriteLine("Erro.");
                return;
            }

          
            Console.Write("Digite um número entre 0 e 10: ");
            if (!int.TryParse(Console.ReadLine(), out int numeroUsuario) || numeroUsuario < 0 || numeroUsuario > 10)
            {
                Console.WriteLine("Número inválido. Use um número entre 0 e 10.");
                return;
            }

       
            Random rand = new Random();
            int numeroComputador = rand.Next(0, 11);

            Console.WriteLine($"O computador escolheu: {numeroComputador}");

            int soma = numeroUsuario + numeroComputador;
            string resultado = soma % 2 == 0 ? "par" : "impar";

            Console.WriteLine($"A soma é {soma}, que é {resultado}.");

            if (escolhaUsuario == resultado)
                Console.WriteLine("Você ganhou!");
            else
                Console.WriteLine("Você perdeu!");
        }
    }
}
