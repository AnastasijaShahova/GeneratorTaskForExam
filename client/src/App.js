import React, { useState } from "react";
import { BrowserRouter as Router } from "react-router-dom";
import { useRoutes } from "./routes";
import { Navbar } from "./components/Navbar";
import "materialize-css";
import { useAuth } from "./hooks/auth.hook";
import { AuthContext } from "./context/AuthContext";
import "./App.scss"
import AuthModal from "./components/ErrorModal";

function App() {
    const [modal, setModal] = useState({
        active: false,
        content: "",
    });

    const { token, login, logout, userId } = useAuth(setModal);
    const isAuth = !!token;
    const routes = useRoutes(isAuth);

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
                <div className="app">
                    {routes}
                    <AuthModal
                        active={modal.active}
                        setActive={setModal}
                        content={modal.content}
                    />
                </div>
            </Router>
        </AuthContext.Provider>
    );
}

export default App;
