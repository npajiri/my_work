const e = require("express");
const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const experienceSchema = new Schema({
  title: { type: String, required: true },
  subTitle: { type: String, required: true },
  date: { type: String, required: true },
  description: { type: String, required: true },
});

const educationSchema = new Schema({
  title: { type: String, required: true },
  subTitle: { type: String, required: true },
  date: { type: String, required: true },
  description: { type: String, required: true },
});

const portfolioInfoSchema = new Schema(
  {
    experience: [experienceSchema],
    education: [educationSchema],
  },
  {
    timestamps: true, // Automatically manage createdAt and updatedAt fields
  }
);

const PortfolioInfo = mongoose.model("PortfolioInfo", portfolioInfoSchema);
module.exports = PortfolioInfo;
