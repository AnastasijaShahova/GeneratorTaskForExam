import React from "react";
import { BrowserRouter as Router } from "react-router-dom";
import { useRoutes } from "./routes";
import { useAuth } from "./hooks/auth.hook";
import { AuthContext } from "./context/AuthContext";
import Navbar from "./components/Navbar";
import "./App.scss";

function App() {
    const { login, logout, userId, role, name } = useAuth();

    const isAuth = !!userId;
    const routes = useRoutes(isAuth, role);

    return (
        <AuthContext.Provider
            value={{
                name,
                login,
                logout,
                userId,
                isAuth,
                role,
            }}
        >
            <Router>
                {isAuth && <Navbar userName={name} userRole={role} />}
                <div className={`app ${isAuth ? "white" : "violet"}`}>
                    {routes}
                </div>
            </Router>
        </AuthContext.Provider>
    );
}

export default App;
