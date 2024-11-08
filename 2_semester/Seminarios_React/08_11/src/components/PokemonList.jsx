import { useEffect, useState } from "react";
import PokemonCard from "./PokemonCard";

function PokemonList() {
  const [selectedPokemon, setSelectedPokemon] = useState(null);
  const [pokemonList, setPokemonList] = useState([]);

  const handleCardClick = (pokemon) => {
    setSelectedPokemon(pokemon);
  };

  useEffect(() => {
    const fetchPokemonDetails = async () => {
      try {
        const response = await fetch('https://pokeapi.co/api/v2/pokemon?limit=151');
        const data = await response.json();

        const detailedPokemonList = await Promise.all(
          data.results.map(async (pokemon) => {
            const response = await fetch(pokemon.url);
            const details = await response.json();

            return {
              id: details.id,
              name: capitalizeFirstLetter(details.name),
              image: `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${details.id}.png`,
              type: details.types.map((typeInfo) => typeInfo.type.name).join("/ ")
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

  // Função auxiliar para capitalizar a primeira letra
  const capitalizeFirstLetter = (string) => {
    return string.charAt(0).toUpperCase() + string.slice(1);
  };

  return (
    <div>
      {selectedPokemon ? (
        <div>
          <h2>Detalhes do Pokémon</h2>
          <PokemonCard
            id={selectedPokemon.id}
            name={selectedPokemon.name}
            image={selectedPokemon.image}
            type={selectedPokemon.type}
          />
          <button onClick={() => setSelectedPokemon(null)}>Voltar</button>
        </div>
      ) : (
        <div className="pokemon-list card">
          {pokemonList.map((pokemon, index) => (
            <PokemonCard
              key={index}
              id={pokemon.id}
              name={pokemon.name}
              image={pokemon.image}
              type={pokemon.type}
              onClick={() => handleCardClick(pokemon)}
            />
          ))}
        </div>
      )}
    </div>
  );
}

export default PokemonList;
