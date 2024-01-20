import Navbar from "../Navbar";
import { Outlet } from "react-router-dom";
import "./index.css";

const Layout = ({ title }) => {
  return (
    <div className="App">
      <Navbar title={title} />
      <div className="main">
        <Outlet />
      </div>
    </div>

  );
};

export default Layout;
