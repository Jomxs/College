
    function PokemonCard({name, type, image, numero, type_class}){
        return(
        <div className='box'>
            <h2>{name}</h2>
            <img src={image} alt={name} />
                <div style={{ display: 'flex',flexDirection: 'column', marginLeft: '50px' , marginRight: '50px' }}>
                    <p>Id: {numero}</p>
                    <br />
                    <p className={type_class}>Tipo: {type}</p>
            </div>

        </div>


        )
    }
    export default PokemonCard;