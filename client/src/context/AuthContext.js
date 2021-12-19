import { createContext } from "react";

function noop() {}

export const AuthContext = createContext({
    token: null,
    userId: null,
    role: "ученик",
    login: noop,
    logout: noop,
    isAuth: false,
    setModal: noop,
});
