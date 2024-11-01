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
      numero="001"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/1.png"
      type="Grass / Poison"
      type_class="Grass"
      />
      </div>
      <div>
      <PokemonCard 
      name="Ivysaur"
      numero="002"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/2.png"
      type="Grass / Poison"
      type_class="Grass"
      />
      </div>
      <div>
      <PokemonCard 
      name="Venosaur"
      numero="003"
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
      numero="004"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/4.png"
      type="Fire"
      type_class="Fire"
      />
      </div>
      <div>
      <PokemonCard 
      name="Charmeleon"
      numero="005"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/5.png"
      type="Fire"
      type_class="Fire"
      />
      </div>
      <div>
      <PokemonCard 
      name="Charizard"
      numero="006"
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
      numero="007"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/7.png"
      type="Water"
      type_class="Water"
      />
      </div>
      <div>
      <PokemonCard 
      name="Wartortle"
      numero="008"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/8.png"
      type="Water"
      type_class="Water"
      />
      </div>
      <div>
      <PokemonCard 
      name="Blastoise"
      numero="009"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/9.png"
      type="Water"
      type_class="Water"
      />
      </div>
    </div>


    <div className="Inseto card">
      <div>
      <PokemonCard 
      name="Caterpie"
      numero="010"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/10.png"
      type="Bug"
      type_class="Bug"
      />
      </div>
      <div>
      <PokemonCard 
      name="Metapod"
      numero="011"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/11.png"
      type="Bug"
      type_class="Bug"
      />
      </div>
      <div>
      <PokemonCard 
      name="Butterfree"
      numero="012"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/12.png"
      type="Bug / Flying"
      type_class="Bug"
      />
      </div>
      <div>
      <PokemonCard 
      name="Weedle"
      numero="013"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/13.png"
      type="Bug / Poison"
      type_class="Bug / Poison"
      />
      </div>
      <div>
      <PokemonCard 
      name="Kakuna"
      numero="014"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/14.png"
      type="Bug / Poison"
      type_class="Bug / Poison"
      />
      </div>
      <div>
      <PokemonCard 
      name="Beedrill"
      numero="015"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/15.png"
      type="Bug / Poison"
      type_class="Bug / Poison"
      />
      </div>
    </div>
    <div className="Normal card">
      <div>
      <PokemonCard 
      name="Pidgey"
      numero="016"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/16.png"
      type="Normal / Flying"
      type_class="Common"
      />
      </div>
      <div>
      <PokemonCard 
      name="Pidgotto"
      numero="017"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/17.png"
      type="Normal / Flying"
      type_class="Common"
      />
      </div>
      <div>
      <PokemonCard 
      name="Pidgeot"
      numero="018"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/18.png"
      type="Normal / Flying"
      type_class="Common"
      />
      </div>
      <div>
      <PokemonCard 
      name="Rattata"
      numero="019"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/19.png"
      type="Normal"
      type_class="Common"
      />
      </div>
      <div>
      <PokemonCard 
      name="Raticate"
      numero="020"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/20.png"
      type="Normal"
      type_class="Common"
      />
      </div>
      <div>
      <PokemonCard 
      name="Spearow"
      numero="021"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/21.png"
      type="Normal / Flying"
      type_class="Common"
      />
      </div>
      <div>
      <PokemonCard 
      name=" Fearow"
      numero="022"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/22.png"
      type="Normal / Flying"
      type_class="Common"
      />
      </div>



    </div>
    <div className="Voador card">
    <div>
      <PokemonCard 
      name="Butterfree"
      numero="012"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/12.png"
      type="Bug / Flying"
      type_class="Bug / Flying"
      />
      </div>
    <div>
      <PokemonCard 
      name="Pidgey"
      numero="016"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/16.png"
      type="Normal / Flying"
      type_class="Flying"
      />
      </div>
      <div>
      <PokemonCard 
      name="Pidgotto"
      numero="017"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/17.png"
      type="Normal / Flying"
      type_class="Flying"
      />
      </div>
      <div>
      <PokemonCard 
      name="Pidgeot"
      numero="018"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/18.png"
      type="Normal / Flying"
      type_class="Flying"
      />
      </div>
      </div>


      
      <div className="Veneno card">
      <PokemonCard 
      name="Ekans" 
      numero="023"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/23.png"
      type="Poison"
      type_class="Poison"
      />
       <PokemonCard 
      name="Arbok" 
      numero="024"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/24.png"
      type="Poison"
      type_class="Poison"
      />
      <PokemonCard 
      name="Nidoran♀" 
      numero="029"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/29.png"
      type="Poison"
      type_class="Poison"
      />
       <PokemonCard 
      name="Nidorana♀" 
      numero="030"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/30.png"
      type="Poison"
      type_class="Poison"
      />
      <PokemonCard 
      name="Nidoqueen♀" 
      numero="031"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/31.png"
      type="Poison"
      type_class="Poison"
      />
      <PokemonCard 
      name="Nidoran♂" 
      numero="032"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/32.png"
      type="Poison"
      type_class="Poison"
      />
      <PokemonCard 
      name="Nidorino♂" 
      numero="033"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/33.png"
      type="Poison"
      type_class="Poison"
      />
      <PokemonCard 
      name="Nidoking♂" 
      numero="034"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/34.png"
      type="Poison"
      type_class="Poison"
      />
    
      </div>
      <div className="Eletrico card">
      <PokemonCard 
      name="Picachu" 
      numero="025"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/25.png"
      type="Eletric"
      type_class="Eletric"
      />
      <PokemonCard 
      name="Raichu" 
      numero="026"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/26.png"
      type="Eletric"
      type_class="Eletric"
      />
      </div>



      <div className="Terra card">
      <PokemonCard 
      name="Sandshrew" 
      numero="027"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/27.png"
      type="Ground"
      type_class="Ground"
      />
      <PokemonCard 
      name="Sandslash" 
      numero="028"
      image="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/28.png"
      type="Eletric"
      type_class="Eletric"
      />
      </div>
  </header>
</div>

  );
}

export default App;
