import { useState } from "react";
import "./index.css";

const Create = () => {
  const [createNewProduct, setCreateNewProduct] = useState({
    _id: 0,
    title: "",
    price: 0.0,
    description: "",
    category: "",
    image: "http://127.0.0.1:4000/images/",
    rating: { rate: 0.0, count: 0 },
  });

  function handleChange(e) {
    const value = e.target.value;
    const name = e.target.name;
    setCreateNewProduct((prevProduct) => ({
      ...prevProduct,
      [name]: value,
      rating: {
        ...prevProduct.rating,
        [name]: name === "count" ? parseInt(value) : parseFloat(value),
      },
    }));
  }

  function handleOnSubmit(e) {
    e.preventDefault();
    console.log(e.target.value);
    fetch("http://localhost:4000/create", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(createNewProduct),
    })
      .then((response) => response.json())
      .then((data) => {
        console.log("Post a new product completed");
        console.log(data);
        if (data) {
          const value = Object.values(data);
          alert(value);
        }
      });
  }

  return (
    <div className="createProduct">
      <h1 className="title">Create New Product</h1>
      <div className="productForm">
        <form action="">
          <input
            type="number"
            placeholder="id"
            name="_id"
            onChange={handleChange}
          />
          <input
            type="text"
            placeholder="title"
            name="title"
            onChange={handleChange}
          />
          <input
            type="number"
            placeholder="price"
            name="price"
            onChange={handleChange}
          />
          <input
            type="text"
            placeholder="description"
            name="description"
            onChange={handleChange}
          />
          <input
            type="text"
            placeholder="category"
            name="category"
            onChange={handleChange}
          />
          <input
            type="text"
            placeholder="image"
            name="image"
            defaultValue="http://127.0.0.1:4000/images/" 
            onChange={handleChange}
          />
          <input
            type="number"
            placeholder="rating"
            name="rate"
            onChange={handleChange}
          />
          <input
            type="number"
            placeholder="count"
            name="count"
            onChange={handleChange}
          />
          <button type="submit" onClick={handleOnSubmit}>
            Submit
          </button>
        </form>
      </div>
    </div>
  );
};

export default Create;
