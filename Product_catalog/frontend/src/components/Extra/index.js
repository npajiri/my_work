import "./index.css";

const Extra = ({ text }) => {
  return (
    <div className="extra-container">

      <h1 className="extra-title">Nnamdi Ajiri - Software Engineering</h1>
      {/* <h2 className="extra-subtitle">npajiri@iastate.edu</h2> */}
      <a href="mailto:npajiri@iastate.edu">npajiri@iastate.edu</a>
      
      <h1 className="extra-title">Ian Bussan - Software Engineering</h1>
      {/* <h2 className="extra-subtitle">iibussan@iastate.edu</h2> */}
      <a href="mailto:npajiri@iastate.edu">iibussan@iastate.edu</a>

      <h1 className="extra-title">Malayah Powlette - LAS</h1>
      {/* <h2 className="extra-subtitle">mmpowl@iastate.edu</h2> */}
      <a href="mailto:npajiri@iastate.edu">mmpowl@iastate.edu</a>

      <p className="extra-info">
        SE/COM S 319
        <br />
        12/10/23
        <br />
        Professor Abraham Netzahualcoy Aldaco
      </p>

      <p className="extra-text">
        <p>
          This website showcases the MERN stack and demonstrates how to perform
          CRUD operations using Node and Express
          <br />
          operations with Node and Express. <br />
          These operations can be used to modify a database of products from the
          fakestore.
        </p>
      </p>


      
{/* 
      <h1 className="extra-title">Aregbe David</h1>
      <h2 className="extra-subtitle">aregbed@iastate.edu</h2>
      <p className="extra-info">
        SE/COM S 319
        <br />
        4/27/23
        <br />
        Professor Abraham Aldaco
      </p>
      <p className="extra-text">
        <p>
          This website showcases the MERN stack and demonstrates how to perform
          CRUD operations using Node and Express
          <br />
          operations with Node and Express. <br />
          These operations can be used to modify a database of products from the
          fakestore.
        </p>
      </p>  */}
    </div>

    
  );
};

export default Extra;
