using System;

class Program
{
    static void Main()
    {
        Console.Write("Quantos dados serão lançados? ");
        if (int.TryParse(Console.ReadLine(), out int quantidade) && quantidade > 0)
        {
            int[] contagem = new int[6]; 
            Random rnd = new Random();

            for (int i = 0; i < quantidade; i++)
            {
                int resultado = rnd.Next(1, 7); 
                contagem[resultado - 1]++;
            }

            Console.WriteLine("\nResultado:");
            for (int i = 0; i < contagem.Length; i++)
            {
                Console.WriteLine($"Face {i + 1}: {contagem[i]} vez(es)");
            }
        }
        else
        {
            Console.WriteLine("Erro.");
        }

        Console.WriteLine("\n...");
        Console.ReadKey();
    }
}
