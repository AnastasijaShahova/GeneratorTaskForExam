import { createContext } from "react";

function noop() {}

export const AuthContext = createContext({
    name: null,
    token: null,
    userId: null,
    role: "ученик",
    login: noop,
    logout: noop,
    isAuth: false,
    setModal: noop,
    modal: { active: false, content: "" },
    setMessage: noop
});
