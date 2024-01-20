import { Route, Routes } from "react-router-dom";
import Layout from "./components/Layout";
import Create from "./components/Create";
import Update from "./components/Update";
import Read from "./components/Read";
import Delete from "./components/Delete";
import Extra from "./components/Extra";
import "./App.css";
import "./bootstrap.min.css";

function App() {

  return (
    <>
      <Routes>
        <Route path="/" element={<Layout />}>
          <Route index element={<Read />} />
          <Route path="create" element={<Create />} />
          <Route path="delete" element={<Delete />} />
          <Route path="update" element={<Update />} />
          <Route path="extra" element={<Extra text="Some text here" />} />
        </Route>
      </Routes>
    </>
  );
}

export default App;
