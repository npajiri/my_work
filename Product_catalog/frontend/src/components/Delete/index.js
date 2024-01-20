import { useState, useEffect } from "react";
import "./index.css";

const Delete = () => {
  const [product, setProduct] = useState([]);

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

  function deleteProduct() {
    var confirmDelete = window.confirm(
      `Are you sure you want to delete ${product.title}?`
    );
    if (confirmDelete) {
      fetch("http://localhost:4000/delete/", {
        method: "DELETE",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ _id: product[0]._id }),
      })
        .then((response) => response.json())
        .then((data) => {
          if (data) {
            const value = Object.values(data);
          }
        });
    }
  }

  return (
    <div className="deleteProduct">
      <h1 className="title">Delete Product</h1>
      <input className="inp"
        type="text"
        id="message"
        name="message"
        placeholder="id"
        onChange={(e) => getProductById(e.target.value)}
      />
      <button className="but" onClick={() => deleteProduct()}>Delete</button>
      <div className="selectedProduct">{showProduct}</div>
    </div>
  );
};

export default Delete;
