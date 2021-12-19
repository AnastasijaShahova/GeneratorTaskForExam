import React, { useState } from "react";
import { BrowserRouter as Router } from "react-router-dom";
import { useRoutes } from "./routes";
import { useAuth } from "./hooks/auth.hook";
import { AuthContext } from "./context/AuthContext";
import AuthModal from "./components/AuthModal";
import Navbar from "./components/Navbar"
import "./App.scss"
import "materialize-css";

function App() {
    const [modal, setModal] = useState({
        active: false,
        content: "",
    });

    const { token, login, logout, userId } = useAuth(setModal);
    // const isAuth = !!token;
    const isAuth = true
    const routes = useRoutes(true);

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
                <div className={`app ${isAuth ? 'white' : 'violet'}`}>
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
