import React from 'react'
import "../styles/AuthModal.scss"

const AuthModal = ({active, setActive, content}) => {
    return (
        <div className={active ? "modal active" : "modal"} onClick={() => setActive(false)}>
            <div className="modal__content" onClick={e => e.stopPropagation()}>
                <h1>Ошбика</h1>
                <p>{content}</p>
            </div>
        </div>
    )
}

export default AuthModal