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

    const { name, login, logout, userId, role } = useAuth();
    // const isAuth = !!userId;
    const isAuth = true;
    const routes = useRoutes(true);

    return (
        <AuthContext.Provider
            value={{
                name,
                login,
                logout,
                userId,
                isAuth,
                role
            }}
        >
            <Router>
                {isAuth && <Navbar userName={name} userRole={role}/>}
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
