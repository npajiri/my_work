import React from "react";
import {BsInfoCircleFill} from "react-icons/bs"
import PageHeaderContent from "../../components/pageHeaderContent";
import { Animate } from "react-simple-animate";
import "./styles.scss";
import {DiReact, DiAndroid} from "react-icons/di"
import {FaDev, FaDatabase} from "react-icons/fa"




const personalDetails = [
    {
        label: "Name",
        value: "Prince Nnamdi Ajiri",
    },
    {
        label: "Age",
        value: "18",
    },
    {
        label: "Address",
        value: "USA",
    },
    {
        label: "Email",
        value: "npajiri@iastate.edu",
    },
    {
        label: "Contact No",
        value: "+1 5153442292",
    }
];

const jobSummary = "Junior in College studying Software Engineering. I am hoping to get an internship in which I can use my Computer Science/Software Engineering skills to impact the company positively."

const About = () => {
    return(
        <section id="about" className="about">

            <PageHeaderContent
            headerText = "About Me"
            icon={<BsInfoCircleFill size={40} />}
            />
            
            <div className="about__content">
                <div className="about__content__personalWrapper">
                <Animate
                play
                duration={1.5}
                delay={1}
                start={{
                    transform: "translateX(-900px)",
                }}

                end={{
                    transform: "translatex(0px)",
                }}
                >


                <h3>Sotware Engineer</h3>
                <p>{jobSummary}</p>

                </Animate>


                <Animate
                play
                duration={1.5}
                delay={1}
                start={{
                    transform: "translateX(500px)",
                }}

                end={{
                    transform: "translatex(0px)",
                }}
                >

                <h3 className="personalInformationHeaderText">Personal Information</h3>
                <ul>
                    {
                        personalDetails.map((item,i)=>(
                            <li key={i}>
                                <span className="title">{item.label}</span>
                                <span className="value">{item.value}</span>
                            </li>
                        ))
                    }
                </ul>
                </Animate>
                </div>



                <div className="about__content__servicesWrapper">
                    <Animate
                    play
                    duration={1.5}
                    delay={1}
                    start={{
                        transform: "translateX(600px)",
                    }}

                    end={{
                        transform: "translatex(0px)",
                    }}
                >
                    <div className="about__content__servicesWrapper__innerContent">

                        <div>
                            <FaDev size={60} color="var(--yellow-theme-main-color)"/>
                        </div>

                        <div>
                            <DiAndroid size={60} color="var(--yellow-theme-main-color)"/>
                        </div>

                        <div>
                            <FaDatabase size={60} color="var(--yellow-theme-main-color)"/>
                        </div>

                        <div>
                            <DiReact size={60} color="var(--yellow-theme-main-color)"/>
                        </div>

                    </div>
                    </Animate>

                </div>

            </div>
        </section>
    );
};

export default About;