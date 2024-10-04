import gato from './gato.png';
import './App.css';
import MeuComponente from './MeuComponente';

function App() {
  const nome = "José Carvalho Neto";
  const hb1 = "Video Game";
  const hb2 = "Academia";
  const hb3 = "Ver Youtube";
  const hb4 = "Ler Manga";
  const hb5 = "Assistir Anime";

  return (
    <div className="App">
      <header className="App-header">
        <img src={gato} className="App-logo" alt="gato" />
        <p>
          O melhor aplicativo que tem:
        </p>
        <a
          className="App-link"
          href="https://web.whatsapp.com"
          target="_blank"
          rel="noopener noreferrer"
        >
          Whatsapp web 👍
        </a>
        <MeuComponente nomeComplet={nome} hobby1={hb1} hobby2={hb2} hobby3={hb3} hobby4={hb4} hobby5={hb5} 
        />
      </header>
    </div>
  );
}

export default App;
