import React from "react";
import { BrowserRouter as Router } from "react-router-dom";
import { useRoutes } from "./routes";
import { Navbar } from "./components/Navbar";
import { Loader } from "./components/Loader";
import "materialize-css";

function App() {
    const ready = true;
    const routes = useRoutes(false);

    if (!ready) {
        return <Loader />;
    }

    return (
        <Router>
            {<Navbar />}
            <div>{routes}</div>
        </Router>
    );
}

export default App;
