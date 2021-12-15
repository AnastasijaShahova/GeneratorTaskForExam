import React from "react";
import { BrowserRouter as Router } from "react-router-dom";
import { useRoutes } from "./routes";
import { Navbar } from "./components/Navbar";
import { Loader } from "./components/Loader";
import "materialize-css";
import { useAuth } from "./hooks/auth.hook";
import { AuthContext } from "./context/AuthContext";
import "./App.scss"

function App() {
    const { token, login, logout, userId } = useAuth();
    const isAuth = !!token;
    const ready = true;
    const routes = useRoutes(isAuth);

    if (!ready) {
        return <Loader />;
    }

    return (
        <AuthContext.Provider
            value={{
                token,
                login,
                logout,
                userId,
                isAuth,
            }}
        >
            <Router>
                {isAuth && <Navbar />}
                <div className="app">{routes}</div>
            </Router>
        </AuthContext.Provider>
    );
}

export default App;
