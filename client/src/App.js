import React, { useState } from "react";
import { BrowserRouter as Router } from "react-router-dom";
import { useRoutes } from "./routes";
import { useAuth } from "./hooks/auth.hook";
import { AuthContext } from "./context/AuthContext";
import Navbar from "./components/Navbar"
import "./App.scss"

function App() {
    const [modal, setModal] = useState(false);
    const [message, setMessage] = useState("")
    const { name, login, logout, userId, role } = useAuth();
    // const isAuth = !!userId;
    const isAuth = true; // Заглушка
    const routes = useRoutes(isAuth);

    return (
        <AuthContext.Provider
            value={{
                name,
                login,
                logout,
                userId,
                isAuth,
                role,
                setModal,
                setMessage
            }}
        >
            <Router>
                {isAuth && <Navbar userName={name} userRole={role}/>}
                <div className={`app ${isAuth ? 'white' : 'violet'}`}>
                    {routes}
                    {/* <AuthModal
                        active={modal}
                        setActive={setModal}
                        content={message}
                    /> */}
                    
                </div>
            </Router>
        </AuthContext.Provider>
    );
}

export default App;
