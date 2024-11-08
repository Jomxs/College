import './PokemonCard.css';

function PokemonCard({ id, name, type, image, onClick }) {
  const types = type.includes('/') ? type.split('/') : [type];
  const mainType = types[0].toLowerCase();
  const button = types.map((t) => (
    <p className={`type-${t.toLowerCase()}`} key={t}>{t}</p>
  ));


  const formatId = (id) => {
    return id.toString().padStart(3, '0'); 
  };

  return (
    <div onClick={onClick} className={`onClick bg-type-${mainType}`}>
      <h2>{name}</h2>
      <p className="pokemon-id">ID: #{formatId(id)}</p> 
      <img src={image} alt={name} />
      {button}
    </div>
  );
}

export default PokemonCard;
