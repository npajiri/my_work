const express = require("express");
const cors = require("cors");
const mongoose = require("mongoose");
const path = require("path");

require("dotenv").config(); // Load environment variables

const portfolioInfoRouter = require("./routes/portfolioInfo");

const app = express();
const port = process.env.PORT || 5000; // Use port 5000 for the backend

// Middleware
app.use(cors()); // Enable Cross-Origin Resource Sharing
app.use(express.json()); // Allow server to accept JSON in the body of requests

// A simple test route
app.get("/", (req, res) => {
  res.send("Hello from the backend!");
});

app.use("/portfolio-info", portfolioInfoRouter); // Use the portfolioInfo router for handling requests to /portfolioInfo

app.get("/download-resume", (req, res) => {
  const filePath = path.join(
    __dirname,
    "public",
    "Nnamdi Resume(2025)-Fulltime.pdf"
  ); // Adjust the path to your resume file
  res.download(filePath, "Nnamdi_Ajiri_Resume.pdf", (err) => {
    if (err) {
      console.error("Error downloading the file:", err);
      res.status(500).send("Error downloading the file.");
    }
  });
});

const uri = process.env.ATLAS_URI;
mongoose.connect(uri);
const connection = mongoose.connection;
connection.once("open", () => {
  console.log("MongoDB database connection established successfully");
});

app.listen(port, () => {
  console.log(`Server is running on port: ${port}`);
});
