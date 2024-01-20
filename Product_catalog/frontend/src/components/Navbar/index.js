import { NavLink } from "react-router-dom";
import "./index.css";

const Navbar = () => {
  return (
    <div className="nav-bar">
      <nav>
        <NavLink exact="true" to="/">
          <h2>35 Interior</h2>
        </NavLink>
        <NavLink exact="true" to="/create">
          <h2>Create</h2>
        </NavLink>
        <NavLink exact="true" to="/update">
          <h2>Update</h2>
        </NavLink>
        <NavLink exact="true" to="/delete">
          <h2>Delete</h2>
        </NavLink>
        <NavLink exact="true" to="/extra">
          <h2>About Us</h2>
        </NavLink>
      </nav>
    </div>

    
  );
};

export default Navbar;
