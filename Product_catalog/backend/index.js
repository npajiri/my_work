const express = require("express");
const cors = require("cors");
const mongoose = require("mongoose");
const app = express();
app.use(express.json());
app.use(cors());
app.use(express.static("public"));
app.use("/images", express.static("images"));

mongoose.connect("mongodb://127.0.0.1:27017/reactdata", {
  dbName: "reactdata",
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

const ReactFormDataSchema = new mongoose.Schema(
  {
    _id: { type: Number },
    title: { type: String },
    price: { type: Number },
    description: { type: String },
    category: { type: String },
    image: { type: String },
    rating: {
      rate: { type: Number },
      count: { type: Number },
    },
  },
  { collection: "products" }
);
const Product = mongoose.model("Product", ReactFormDataSchema);

const port = process.env.PORT || 4000;
const host = "localhost";

app.get("/", async (req, res) => {
  try {
    const query = {};
    const allProducts = await Product.find(query);
    console.log(allProducts);
    res.send(allProducts);
  } catch (error) {
    console.error(error);
    res.status(500).send("Internal Server Error");
  }
});

app.get("/:id", async (req, res) => {
  try {
    const id = req.params.id;
    const query = { _id: id };
    const oneProduct = await Product.findOne(query);
    console.log(oneProduct);
    if (oneProduct) {
      res.send(oneProduct);
    } else {
      res.status(404).send("Product not found");
    }
  } catch (error) {
    console.error(error);
    res.status(500).send("Internal Server Error");
  }
});

app.post("/create", async (req, res) => {
  console.log(req.body);
  const p_id = req.body._id;
  const ptitle = req.body.title;
  const pprice = req.body.price;
  const pdescription = req.body.description;
  const pcategory = req.body.category;
  const pimage = req.body.image;
  const prate = req.body.rating.rate;
  const pcount = req.body.rating.count;
  const formData = new Product({
    _id: p_id,
    title: ptitle,
    price: pprice,
    description: pdescription,
    category: pcategory,
    image: pimage,
    rating: { rate: prate, count: pcount },
  });

  try {
    await Product.create(formData);
    const messageResponse = { message: `Product ${p_id} added correctly` };
    res.send(JSON.stringify(messageResponse));
  } catch (err) {
    console.log("Error adding a new product:" + err);
  }
});

app.put("/update/:id", async (req, res) => {
  try {
    console.log(req.params.id);
    console.log(req.body);
    const messageResponse = await Product.updateOne(
      { _id: req.params.id },
      { $set: { price: req.body.price } }
    );
    res.send(JSON.stringify(messageResponse));
  } catch (err) {
    console.log("Error updating product: " + err);
  }
});

app.delete("/delete/", async (req, res) => {
  try {
    await Product.deleteOne({ _id: req.body._id });
    const messageResponse = {
      message: `Product ${req.body._id} deleted correctly`,
    };
    res.send(JSON.stringify(messageResponse));
  } catch (err) {
    console.log("Error deleting :" + p_id + " " + err);
  }
});

app.listen(port, () => {
  console.log(`App listening at http://%s:%s`, host, port);
});
