import { useEffect, useState } from "react";
import PokemonCard from "./PokemonCard";

function PokemonList() {
  const [selectedPokemon, setSelectedPokemon] = useState(null);
  const [pokemonList, setPokemonList] = useState([]);
  const [currentPage, setCurrentPage] = useState(1);
  const itemsPerPage = 20;

  // Função chamada ao clicar no cartão do Pokémon para mostrar os detalhes
  const handleCardClick = (pokemon) => {
    setSelectedPokemon(pokemon);
  };

  // Busca os detalhes dos Pokémon da API
  useEffect(() => {
    const fetchPokemonDetails = async () => {
      try {
        const response = await fetch('https://pokeapi.co/api/v2/pokemon?limit=151');
        const data = await response.json();

        // Obter detalhes de cada Pokémon
        const detailedPokemonList = await Promise.all(
          data.results.map(async (pokemon) => {
            const response = await fetch(pokemon.url);
            const details = await response.json();

            return {
              id: details.id,
              name: capitalizeFirstLetter(details.name),
              image: `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${details.id}.png`,
              type: details.types.map((typeInfo) => typeInfo.type.name).join("/ "),
              weight: (details.weight / 10).toFixed(2), // Convertendo de hectogramas para kg
              height: (details.height / 10).toFixed(2), // Convertendo de decímetros para metros
              moves: details.moves.slice(0, 5).map((move) => move.move.name), // Pegando os 5 primeiros golpes
            };
          })
        );
        setPokemonList(detailedPokemonList);
      } catch (error) {
        console.error("Erro ao buscar os dados", error);
      }
    };

    fetchPokemonDetails();
  }, []);

  // Função para capitalizar a primeira letra do nome
  const capitalizeFirstLetter = (string) => {
    return string.charAt(0).toUpperCase() + string.slice(1);
  };

  // Páginação
  const indexOfLastItem = currentPage * itemsPerPage;
  const indexOfFirstItem = indexOfLastItem - itemsPerPage;
  const currentItems = pokemonList.slice(indexOfFirstItem, indexOfLastItem);

  const nextPage = () => {
    if (currentPage < Math.ceil(pokemonList.length / itemsPerPage)) {
      setCurrentPage(currentPage + 1);
    }
  };

  const prevPage = () => {
    if (currentPage > 1) {
      setCurrentPage(currentPage - 1);
    }
  };

  return (
    <div className="pagination">
      {selectedPokemon ? (
        <div>
          <h2>Detalhes do Pokémon</h2>
          <PokemonCard
            id={selectedPokemon.id}
            name={selectedPokemon.name}
            image={selectedPokemon.image}
            type={selectedPokemon.type}
            weight={selectedPokemon.weight}
            height={selectedPokemon.height}
            moves={selectedPokemon.moves}
          />
          <button onClick={() => setSelectedPokemon(null)}>Voltar</button>
        </div>
      ) : (
        <div>
          <div className="pokemon-list card">
            {currentItems.map((pokemon, index) => (
              <PokemonCard
                key={index}
                id={pokemon.id}
                name={pokemon.name}
                image={pokemon.image}
                type={pokemon.type}
                onClick={() => handleCardClick(pokemon)} // Ao clicar, exibe os detalhes
              />
            ))}
          </div>
          <div className="pagination">
            <button onClick={prevPage} disabled={currentPage === 1}>
              Anterior
            </button>
            <span>Página {currentPage}</span>
            <button 
              onClick={nextPage}
              disabled={currentPage === Math.ceil(pokemonList.length / itemsPerPage)}
            >
              Próxima
            </button>
          </div>
        </div>
      )}
    </div>
  );
}

export default PokemonList;
