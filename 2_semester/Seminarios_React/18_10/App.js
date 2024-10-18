import PokemonCard from "./PokemonCard.jsx";
import './App.css';

function App() {
  return (
    
<div className="App">
  <header className="App-header">
 
    <div className="Grama card a">
      <div>
      <PokemonCard 
      name="Bulbasaur" 
      numero="1"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/1.png"
      type="Grass / Poison"
      type_class="Grass"

      />
      </div>
      <div>
      <PokemonCard 
      name="Ivysaur"
      numero="2"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/2.png"
      type="Grass / Poison"
      type_class="Grass"
      />
      </div>
      <div>
      <PokemonCard 
      name="Venosaur"
      numero="3"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/3.png"
      type="Grass / Poison"
      type_class="Grass"
      />
      </div>
    </div>
    <div className="Fogo card">
      <div>
      <PokemonCard 
      name="Charmander"
      numero="4"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/4.png"
      type="Fire"
      type_class="Fire"
      />
      </div>
      <div>
      <PokemonCard 
      name="Charmeleon"
      numero="5"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/5.png"
      type="Fire"
      type_class="Fire"
      />
      </div>
      <div>
      <PokemonCard 
      name="Charizard"
      numero="6"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/6.png"
      type="Fire / Flying"
      type_class="Fire"
      />
      </div>
    </div>

    <div className="Agua card">
      <div>
      <PokemonCard 
      name="Squirtle"
      numero="7"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/7.png"
      type="Water"
      type_class="Water"
      />
      </div>
      <div>
      <PokemonCard 
      name="Wartortle"
      numero="8"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/8.png"
      type="Water"
      type_class="Water"
      />
      </div>
      <div>
      <PokemonCard 
      name="Blastoise"
      numero="9"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/9.png"
      type="Water"
      type_class="Water"
      />
      </div>
    </div>
  </header>
</div>

  );
}

export default App;
