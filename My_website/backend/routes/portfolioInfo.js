const router = require("express").Router();
let PortfolioInfo = require("../models/portfolioinfo.model");

//GET route to fetch portfolio information
router.route("/").get((req, res) => {
  PortfolioInfo.findOne() //findOne because there is only one document
    .then((info) => res.json(info))
    .catch((err) => res.status(400).json("Error: " + err));
});

//POST route to add or update portfolio information
router.route("/add").post((req, res) => {
  const { experience, education } = req.body;
  const newPortfolioInfo = new PortfolioInfo({
    experience,
    education,
  });
  newPortfolioInfo
    .save()
    .then(() => res.json("Portfolio information added successfully!"))
    .catch((err) => res.status(400).json("Error: " + err));
});

module.exports = router;
