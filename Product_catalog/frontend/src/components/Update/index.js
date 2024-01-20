import { useState, useEffect } from "react";
import "./index.css";


const Update = () => {
  const [product, setProduct] = useState([]);
  const [newPrice, setNewPrice] = useState(0);

  const showProduct = product.map((product) => {
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

  function getProductById(id) {
    if (id >= 1 && id <= 20) {
      fetch("http://localhost:4000/" + id)
        .then((response) => response.json())
        .then((data) => {
          const dataArr = [];
          dataArr.push(data);
          setProduct(dataArr);
        });
    }
  }

  function updatePrice() {
    fetch("http://localhost:4000/update/" + product[0]._id, {
      method: "PUT",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ price: newPrice }),
    })
      .then((response) => {
        response.json();
        console.log(response);
      })
      .then((data) => {
        console.log("Put new product price completed");
        console.log(data);
        if (data) {
          const value = Object.values(data);
          alert(value);
        }
      });
  }

  return (
    <div className="updateProduct">
      <h1 className="title">Update Product Price</h1>
      <input className="inp"
        type="text"
        id="message"
        name="message"
        placeholder="id"
        onChange={(e) => getProductById(e.target.value)}
      />
      
      <input className="inp"
        type="number"
        id="newPrice"
        name="newPrice"
        placeholder="new price"
        onChange={(e) => setNewPrice(e.target.value)}
      />
      <button className="but" onClick={() => updatePrice()}>Update</button>

      <div className="selectedProduct">{showProduct}</div>
    </div>
  );
};

export default Update;
