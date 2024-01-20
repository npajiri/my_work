import React, { useState } from "react";
import { BsInfoCircleFill } from "react-icons/bs";
import PageHeaderContent from "../../components/pageHeaderContent";
import ImageOne from "../../images/C.webp";
import ImageTwo from "../../images/C++.jpg";
import ImageThree from "../../images/java.jpg";
import ImageFour from "../../images/react.jpg";
import ImageFive from "../../images/verilog.jpg";
import ImageSix from "../../images/html.jpeg";
import "./styles.scss";


const portfolioData = [
    {
        id : 2,
        name : "Chess Game",
        image : ImageOne,
        link : "https://github.com/npajiri/my_work/tree/main/Chess_game"
    },
    {
        id : 2,
        name : "Pokemon Game",
        image : ImageTwo,
        link : "https://github.com/npajiri/my_work/tree/main/Pokemon_game"
    },
    {
        id : 2,
        name : "Events App",
        image : ImageThree,
        link : ""
    },
    {
        id : 3,
        name : "Portfolio",
        image : ImageFour,
        link : ""
    },
    {
        id : 2,
        name : "Elevator",
        image : ImageFive,
        link : "https://github.com/npajiri/my_work/tree/main/Elevator_simulator"
    },
    {
        id : 3,
        name : "Ecommerce",
        image : ImageSix,
        link : "https://github.com/npajiri/my_work/tree/main/Product_catalog"
    }
    
];

const filterData = [
    {
        filterId : 1 ,
        label : "All"
    },
    {
        filterId : 2 ,
        label : "Development"
    },
    {
        filterId : 3 ,
        label : "Design"
    }
];

const Portfolio = () => {

const [filteredvalue,setFilteredValue] = useState(1)
const [hoveredValue,setHoveredValue] = useState(null)

function handleFilter(currentId){
    setFilteredValue(currentId)
};

function handleHover(index){
    setHoveredValue(index)
};

console.log("===============================");
console.log(hoveredValue);
console.log("===============================");

const filteredItems = filteredvalue === 1 ? portfolioData : 
portfolioData.filter(item=>item.id === filteredvalue)

console.log(filteredItems);

    return(
        <section id="portfolio" className="portfolio">

            <PageHeaderContent
            headerText = "My Portfolio"
            icon={<BsInfoCircleFill size={40} />}
            />
            <div className="portfolio__content">
                <ul className="portfolio__content__filter">
                    {filterData.map(item=>(
                        <li className={item.filterId === filteredvalue ? 'active' : ''} onClick={()=>handleFilter(item.filterId)} key={item.filterId}>{item.label}</li>
                    ))}
                </ul>
                <div className="portfolio__content__cards">

                    {filteredItems.map((item,index)=>(
                            <div 
                            className="portfolio__content__cards__item" 
                            key={`cardItem${item.name.trim()}`}
                            onMouseEnter={()=>handleHover(index)}
                            onMouseLeave={()=>handleHover(null)}
                            >

                                <div className="portfolio__content__cards__item__img-wrapper">
                                    <a>
                                        <img alt="dummy data" src={item.image}/>
                                    </a>
                                </div>
                                <div className="overlay">

                                    {
                                        index === hoveredValue && (
                                            <div>
                                                <p>{item.name}</p>
                                                <a href={item.link} target="_blank"><button>Visit</button></a>
                                            </div>
                                        )
                                    }

                                </div>
                            </div>
                        ))}

                </div>
            </div>
        </section>
    )
}

export default Portfolio;