import { useState, useEffect } from "react";
import "./index.css";

const Read = () => {
  const [products, setProducts] = useState([]);
  const [oneProduct, setOneProduct] = useState([]);


  const showAllProducts = products.map((product) => {
    return (
      <div key={product._id} className="productCard">
        <img src={product.image} alt={product.title} /> <br />
        <h2>{product.title}</h2> <br />
        <h3>${product.price}</h3> <br />
        <p className="describe">{product.description}</p> <br />
        <p>
          <strong>Category: </strong>
          {product.category}
        </p>{" "}
        <br />
        <p>
          <strong>Rating: </strong> {product.rating.rate} (
          {product.rating.count})
        </p>{" "}
        <br />
      </div>
    );
  });


  const showOneProduct = oneProduct.map((product) => {
    return (
      <div key={product._id} className="productCard">
        <img src={product.image} alt={product.title} style={{ width: '50%', height: '50%' }}/> <br />
        <h2>{product.title}</h2> <br />
        <h3>${product.price}</h3> <br />
        <p>{product.description}</p> <br />
        <p>
          <strong>Category: </strong>
          {product.category}
        </p>{" "}
        <br />
        <p>
          <strong>Rating: </strong> {product.rating.rate} (
          {product.rating.count})
        </p>{" "}
        <br />

      </div>
    );
  });

  function getAllProducts() {
    fetch("http://localhost:4000/")
      .then((response) => response.json())
      .then((data) => {
        setProducts(data);
      });
  }

  function getOneProduct(id) {
    if (id >= 1 && id <= 20) {
      fetch("http://localhost:4000/" + id)
        .then((response) => response.json())
        .then((data) => {
          const dataArr = [];
          dataArr.push(data);
          setOneProduct(dataArr);
        });
    }
  }

  useEffect(() => {
    getAllProducts();
  }, []);

  return (
    <div className="readProducts">
      <main className="main">
        <div>
          <h1 className="h35">35 Interior</h1>
          <p className="h35p">Welcome to our interior catalog website!
            <br />
          Now including a search bar at the bottom!</p>
        </div>
      </main>

      {/* <h1 className="title">Products</h1> */}
      <div className="allProducts">{showAllProducts}</div>
      <div className="search-container">
        <h1>Search for Product:</h1>
        <input
          type="text"
          id="message"
          name="message"
          placeholder="id"
          onChange={(e) => getOneProduct(e.target.value)}
        />
      </div>
      <div className="oneProduct">{showOneProduct}</div>
    </div>
  );
};

export default Read;
